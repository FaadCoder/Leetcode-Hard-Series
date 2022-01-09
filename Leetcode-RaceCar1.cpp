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
    int getMinimumNumberOfInstructions()
    {
        int minimumNumberOfInstructions = 0;
        queue<CarAttributes> bfsQueue;
        unordered_set<string> visSet;
        string key = to_string(0) + "," + to_string(1);
        visSet.insert(key);
        bfsQueue.push(CarAttributes(0,1));
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

                // "A" 
                int nextPos = currPos + currSpd;
                int nextSpd = currSpd * 2;
                key = to_string(nextPos) + "," + to_string(nextSpd);
                if(!visSet.count(key) and abs(target - nextPos) < target)
                {
                    visSet.insert(key);
                    bfsQueue.push(CarAttributes(nextPos,nextSpd));
                }
                
                // "R"
                nextPos = currPos;
                nextSpd = currSpd < 0 ? 1 : -1;
                key = to_string(nextPos) + "," + to_string(nextSpd);
                if(!visSet.count(key) and abs(target - nextPos) < target)
                {
                    visSet.insert(key);
                    bfsQueue.push(CarAttributes(nextPos,nextSpd));
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
