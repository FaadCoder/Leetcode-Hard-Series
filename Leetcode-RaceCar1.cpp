/*
License : This file is created by Paras Saini.
Question Link : https://leetcode.com/problems/race-car/
Solution Explanation : https://youtu.be/_Fm9JZDLYHg

*/

class CarAttributes{
private:
    int position,speed;

public:
    CarAttributes(int position,int speed)
    {
        this->position = position;
        this->speed = speed;
    }

    void setPosition(int position)
    {
        this->position = position;
    }

    void setSpeed(int speed)
    {
        this->speed = speed;
    }

    int getPosition()
    {
        return position;
    }

    int getSpeed()
    {
        return speed;
    }
    
};


class Solution {
    int target;
    
    bool isPositionNotFarFromTarget(int position,int target)
    {
        return abs(target - position) < target;
    }
    
    bool isValidInstruction(int position,unordered_set<string> &visSet,string &key,int target)
    {
        return !visSet.count(key) and isPositionNotFarFromTarget(position,target);
    }
    
    int getMinimumNumberOfInstructions()
    {
        int minimumNumberOfInstructions = 0;
        queue<CarAttributes> bfsQueue;
        unordered_set<string> visSet;
        string key = to_string(0) + "," + to_string(1);
        visSet.insert(key);
        bfsQueue.push(CarAttributes(0,1));
        
        // lambda function to deal with repititive work.
        auto moveToNextPos = [&](int nextPosition,int nextSpeed,CarAttributes &carAttribute,string &key){
            visSet.insert(key);
            carAttribute.setPosition(nextPosition);
            carAttribute.setSpeed(nextSpeed);
            bfsQueue.push(carAttribute);
        };
        
        while(!bfsQueue.empty())
        {
            int size = (int)bfsQueue.size();
            while(size--)
            {
                CarAttributes front = bfsQueue.front();
                bfsQueue.pop();
                int currPos = front.getPosition();
                int currSpd = front.getSpeed();

                if(currPos == target)
                return minimumNumberOfInstructions;

                // Explore option : "A" 
                int nextPos = currPos + currSpd;
                int nextSpd = currSpd * 2;
                key = to_string(nextPos) + "," + to_string(nextSpd);
                if(isValidInstruction(nextPos,visSet,key,target))
                {
                    moveToNextPos(nextPos,nextSpd,front,key);
                }
                
                // Explore option : "R"
                nextPos = currPos;
                nextSpd = currSpd < 0 ? 1 : -1;
                key = to_string(nextPos) + "," + to_string(nextSpd);
                if(isValidInstruction(nextPos,visSet,key,target))
                {
                     moveToNextPos(nextPos,nextSpd,front,key);
                }

            }
            minimumNumberOfInstructions += 1;
        }
        return -1;
    }

public:
    int racecar(int target) 
    {
        this->target = target;
        return getMinimumNumberOfInstructions();
    }
};
