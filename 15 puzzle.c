#include<stdio.h>

int table[4][4];

void moveRight()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(table[i][j]==0 && j!=0)
            {
                int temp=table[i][j-1];
                table[i][j-1]=0;
                table[i][j]=temp;
            }
        }
    }
}

void moveLeft()
{
    for(int i=3;i>=0;i--)
    {
        for(int j=3;j>=0;j--)
        {
            if(table[i][j]==0 && j!=3)
            {
                int temp=table[i][j+1];
                table[i][j+1]=0;
                table[i][j]=temp;
            }
        }
    }
}

void moveUp()
{
    for(int i=3;i>=0;i--)
    {
        for(int j=3;j>=0;j--)
        {
            if(table[i][j]==0 && i!=3)
            {
                int temp=table[i+1][j];
                table[i+1][j]=0;
                table[i][j]=temp;
            }
        }
    }
}

void moveDown()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(table[i][j]==0 && i!=0)
            {
                int temp=table[i-1][j];
                table[i-1][j]=0;
                table[i][j]=temp;
            }
        }
    }
}

void displayTable()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(table[i][j]==0)
                printf("   ");
            else if(table[i][j]<10)
                printf("%d  ",table[i][j]);
            else
                printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkForFinish()
{
    int res=0,temp=1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(table[i][j]==temp)
                temp++;
        }
    }
    if(temp==15 || temp==16)
        res=1;
    return res;
}

void moveNumbers()
{
    int key=-1;
    int s;
    while(key!=7)
    {
        printf("Moveup = 1\n");
        printf("Movedown = 2\n");
        printf("Moveleft = 3\n");
        printf("Moveright = 4\n");
        printf("Check =5\n");
        printf("Display =6\n");
        printf("Exit =7\n");
        scanf("%d",&key);
        switch(key)
        {
        case 3:
            moveLeft();
            displayTable();
            break;
        case 4:
            moveRight();
            displayTable();
            break;
        case 1:
            moveUp();
            displayTable();
            break;
        case 2:
            moveDown();
            displayTable();
            break;
        case 5:
            s=checkForFinish();
            if(s==1)
                printf("Game Completed Successfully.\n");
            else
                printf("Continue With Move.\n");
            break;
        case 6:
            displayTable();
        case 7:
            break;
        }
    }
}

void ownSetup()
{
    printf("Enter the table:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            scanf("%d",&table[i][j]);
    }
    displayTable();
    moveNumbers();
}

int main()
{
    ownSetup();

    return 0;
}
