#include "bestfitallocator.h"
#define MAX_FLOAT 999999;
bestFitAllocator::bestFitAllocator()
{

}
void bestFitAllocator::allocate(Process s, QVector<Segment> &segments)
{

   QVector<Segment>p_segments=s.getSegments();
   QVector<Segment>d_segments=segments;
   for(int i=0;i<p_segments.size();i++)
   {
       float size=MAX_FLOAT;
       int pos=-1;
    for(int j=0;j<d_segments.size();j++)
    {
        if(d_segments[j].get_isHole())
        {
            if(size>d_segments[j].getSize()&&p_segments[i].getSize()<=d_segments[j].getSize())
            {
                pos=j;
                size=d_segments[j].getSize();
            }

        }

    }
    if(pos!=-1)
    {
        if(d_segments[pos].getSize()>p_segments[i].getSize())
        {
            /* if segment is allocated and it's size is bigger than required size
             then split the segment into 2 whereas one is free and the other is occupied */

            //free hole segment
            Segment seg(d_segments[pos].get_from()+p_segments[i].getSize(),d_segments[pos].get_to(),"");
            seg.set_isHole(1);
            //the ocuppied part of old segment;
            d_segments[pos].set_to(p_segments[i].getSize());
            d_segments[pos].setSize(p_segments[i].getSize());
            d_segments[pos].set_isHole(0);
            d_segments[pos].set_name(p_segments[i].get_name());
            d_segments[pos].addProcessname(s.getName());
            //finally adding the new hole segment into our memory chunk
            d_segments.insert(d_segments.begin()+pos+1,seg);
        }
        else
        {
            d_segments[pos].set_isHole(0);
        }

    }
    else
     {
      isAllocated=false;
      return;
     }
   }
segments=d_segments;
}
bool bestFitAllocator::is_allocated()
{
    return isAllocated;
}
