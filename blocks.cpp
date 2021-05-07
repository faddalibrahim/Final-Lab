#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// #include <cstdlib>

using namespace std;

class RectBlocks
{
private:
    int L, W, H;

public:
    RectBlocks(int w, int h, int l)
    {
        L = l;
        W = w;
        H = h;
    }
    void setL(int l)
    {
        L = l;
    }

    int getL()
    {
        return L;
    }

    void setW(int w)
    {
        W = w;
    }

    int getW()
    {
        return W;
    }

    void setH(int h)
    {
        H = h;
    }

    int getH()
    {
        return H;
    }
};

class SqrBaseRectBlocks : public RectBlocks
{
public:
    SqrBaseRectBlocks(int l, int w, int h) : RectBlocks(l, w, h)
    {
    }
};

class CuboidBlocks : public SqrBaseRectBlocks
{
public:
    CuboidBlocks(int l, int w, int h) : SqrBaseRectBlocks(l, w, h)
    {
    }
};

class CylindricalBlocks : public SqrBaseRectBlocks
{
public:
    CylindricalBlocks(int w, int h, int l) : SqrBaseRectBlocks(w, h, l)
    {
    }
};

class SphericalBlocks : public CuboidBlocks
{
public:
    SphericalBlocks(int w, int h, int l) : CuboidBlocks(w, h, l)
    {
    }
};

string checkDims(int w, int h, int l)
{
    if (w == h & h == l)
    {
        return "spherical";
    }
    else if (w == h)
    {
        return "cylindrical";
    }
    else if (w != h && h != l)
    {
        return "rect";
    }
}

int main()
{

    // Blocks
    vector<RectBlocks> rect_blocks;
    vector<CylindricalBlocks> cylindrical_blocks; // w = h
    vector<SphericalBlocks> spherical_blocks;     // w = h = l

    ifstream fin("dataBlocks.dat");
    string temp;
    int counter = 0;
    int dim[3];

    while (fin >> temp)
    {
        dim[counter] = stoi(temp);
        counter++;

        if (counter == 3)
        {
            counter = 0;
            string block_type = checkDims(dim[0], dim[1], dim[2]);
            if (block_type == "rect")
            {
                rect_blocks.push_back(RectBlocks(dim[0], dim[1], dim[2]));
            }
            else if (block_type == "spherical")
            {
                spherical_blocks.push_back(SphericalBlocks(dim[0], dim[1], dim[2]));
            }
            else if (block_type == "cylindrical")
            {
                cylindrical_blocks.push_back(CylindricalBlocks(dim[0], dim[1], dim[2]));
            }
        }
    }

    cout << "-----rect blocks-----" << endl;
    for (RectBlocks &rect_block : rect_blocks)
    {
        cout << rect_block.getW() << " " << rect_block.getH() << " " << rect_block.getL() << endl;
    }

    cout << "-----Cylindrical blocks-----" << endl;
    for (CylindricalBlocks &cylindrical_block : cylindrical_blocks)
    {
        cout << cylindrical_block.getW() << " " << cylindrical_block.getH() << " " << cylindrical_block.getL() << endl;
    }

    cout << "-----Shperical blocks-----" << endl;
    for (SphericalBlocks &spherical_block : spherical_blocks)
    {
        cout << spherical_block.getW() << " " << spherical_block.getH() << " " << spherical_block.getL() << endl;
    }
}