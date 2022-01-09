/*
License : This file is created by Paras Saini.
Question Link : https://leetcode.com/problems/race-car/
Solution Explanation : https://youtu.be/_Fm9JZDLYHg

*/

class CarAttributes{
private:
    int speed,position;
public:
    CarAttributes(int speed,int position)
    {
        this->speed = speed;
        this->position = position;
    }
    
    void setSpeed(int speed)
    {
        this->speed = speed;
    }
    
    void setPosition(int position)
    {
        this->position = position;
    }
    
    int getSpeed()
    {
        return speed;
    }
    
    int getPosition()
    {
        return position;
    }
};

class Solution {
    
    int getShortestLengthOfSequence(int target)
    {
        unordered_map<int,unordered_map<int,int>> speedAndPositionVisitedMap;
        queue<CarAttributes> q;
        q.push(CarAttributes(1,0));
        speedAndPositionVisitedMap[0][1] = 1;
        int level = 0;
        
        while(!q.empty())
        {
            int qSize = q.size();
            while(qSize--)
            {
                CarAttributes qFront = q.front();
                q.pop();
                int currentPosition = qFront.getPosition();
                int currentSpeed = qFront.getSpeed();
                if(currentPosition == target)
                {
                    return level;
                }
                // Choice "A"
                int nextPosition = currentPosition + currentSpeed;
                int nextSpeed = currentSpeed * 2;
                
                if(!speedAndPositionVisitedMap[nextPosition][nextSpeed])
                {
                    if(abs(target - nextPosition) < target)
                    {
                        speedAndPositionVisitedMap[nextPosition][nextSpeed] = 1;
                        q.push(CarAttributes(nextSpeed,nextPosition));
                    }
                }
                 
                // Choice "R"
                nextPosition = currentPosition;
                nextSpeed = currentSpeed < 0 ? 1 : -1;
                
                if(!speedAndPositionVisitedMap[nextPosition][nextSpeed])
                {
                    if(abs(target - nextPosition) < target)
                    {
                        speedAndPositionVisitedMap[nextPosition][nextSpeed] = 1;
                        q.push(CarAttributes(nextSpeed,nextPosition));
                    }
                }   
                
            }
            level++;
        }
        
        return -1;
    }
    
public:
    int racecar(int target) 
    {
        return getShortestLengthOfSequence(target);
    }
};
