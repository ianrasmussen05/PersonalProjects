#include "UserInput.h"

UserInput::UserInput()
{
    row = 0;
    col = 0;
    density = 0.0;
}

UserInput::UserInput(unsigned short row, unsigned short col, float density)
{
    setRow(row);
    setCol(col);
    setDensity(density);

    generateBoard(board, getRow(), getCol());
    randomizeBoard(board, getDensity());
}

UserInput::~UserInput()
{
    Helper::deleteBoard(board, row);
}

// The most important function of this class. Gets the user inputs to build out the rest of the program.
// Gets the life from a file or random, choose a mode, choose how the results are delivered.
void UserInput::getUserInput()
{
    std::cout << "------------ Welcome to the Game of Life! ------------" << std::endl;
    
    // Prompt user to use randomization cells or input (from file) cells
    std::cout << "Do you wish to:\n\tStart with a random configuration? (Enter '1')\n\tEnter a flat file. (Enter '2')" << std::endl;
    int inputConfig;
    while (true)
    {
        try 
        {
            int temp;
            std::cin >> temp;

            if (std::cin.fail()) {
                throw std::invalid_argument("Input must be a number.");
            }

            if (temp != 1 && temp != 2) {
                throw std::out_of_range("Input must be '1' or '2'.");
            }

            inputConfig = temp;
            break;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    
    // Generate the boards from the users input
    switch (inputConfig)
    {
        case 1:
            getRandomizeInput();
            break;
        case 2:
            getFileInput();
            break;
        default:
            exit(0);
    }

    // Prompt user which boundary mode to choose
    std::cout << "Choose a boundary mode to run:\n\tClassic (Enter '1')\n\tDoughnut (Enter '2')\n\tMirror (Enter '3')" << std::endl;
    int boardConfig;
    while (true)
    {
        try 
        {
            int temp;
            std::cin >> temp;

            if (std::cin.fail()) {
                throw std::invalid_argument("Input must be a number.");
            }

            if (temp != 1 && temp != 2 && temp != 3) {
                throw std::out_of_range("Input must be '1', '2', or '3'.");
            }

            boardConfig = temp;
            break;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // Prompt user which generationn mode to choose (pause between each or not)
    std::cout << "Choose a generation mode:\n\tPause between each generation (Enter '1')\n\tNo pause (Enter '2')" << std::endl;
    int generationMode;
    while (true) 
    {
        try
        {
            int temp;
            std::cin >> temp;

            if (std::cin.fail()) {
                throw std::invalid_argument("Input must be a number.");
            }

            if (temp != 1 && temp != 2) {
                throw std::out_of_range("Input must be '1' or '2'.");
            }

            generationMode = temp;
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
        
    }

    bool pauseEveryGeneration = (generationMode == 1) ? true : false;
    // Generate the mode from the users input
    switch (boardConfig)
    {
        case 1:
            // classic mode
            generateClassicMode(pauseEveryGeneration);
            break;
        case 2:
            // doughnut mode
            generateDoughnutMode(pauseEveryGeneration);
            break;
        case 3:
            // mirror mode
            generateMirrorMode(pauseEveryGeneration);
            break;
        default:
            exit(0);
    }
}

// User input to get random values for the boards
void UserInput::getRandomizeInput()
{
    std::cout << "------------ Randomize Life ------------" << std::endl;

    unsigned short rows = validateShort("Enter the amount of rows: ");
    unsigned short cols = validateShort("Enter the amount of columns: ");

    float min = 0.0;
    float max = 1.0;
    float density = validateFloat("Enter the density: ", min, max);

    setRow(rows);
    setCol(cols);
    setDensity(density);

    generateBoard(board, this->row, this->col);
    randomizeBoard(board, this->density);
}

// User input to get values from a file for the boards
void UserInput::getFileInput()
{
    std::cout << "------------ Import Life ------------" << std::endl;

    FileInput *file;
    std::string fileName;

    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    file = new FileInput(fileName);
    file->createBoard(this->board, this->row, this->col);

    delete file;
}

// Allocate memory for the 2D array (board) given the row and column sizes
void UserInput::generateBoard(bool**& arr, unsigned short row, unsigned short col)
{
    arr = new bool*[row];
    for (unsigned short i = 0; i < row; ++i) 
    {
        arr[i] = new bool[col]{false};
    }
}

// Method to randomize the cells on the board given the population density (percentage).
void UserInput::randomizeBoard(bool**& arr, float density)
{
    std::srand(time(0));

    for (unsigned short i = 0; i < getRow(); ++i)
    {
        for (unsigned short j = 0; j < getCol(); ++j)
        {
            if (density == 1.0)
            {
                arr[i][j] = 1;
                continue;
            }
            if (density == 0.0)
            {
                arr[i][j] = 0;
                continue;
            }

            int randNum = rand() % 100;
            if (randNum < density*100)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
}

// Method to run simulations in Classic Mode.
void UserInput::generateClassicMode(bool generationMode)
{
    ClassicMode* classic = new ClassicMode(board, row, col);
    
    if (generationMode) // user chooses to pause each generation
    {
        classic->simulateEachStep();
    }
    else // user chooses to not pause
    {
        classic->stimulateToFile();
    }

    delete classic;
}

void UserInput::generateDoughnutMode(bool generationMode)
{
    DoughnutMode* doughnut = new DoughnutMode(board, row, col);
    
    if (generationMode) // user chooses to pause each generation
    {
        doughnut->simulateEachStep();
    }
    else // user chooses to not pause
    {
        doughnut->stimulateToFile();
    }

    delete doughnut;
}

void UserInput::generateMirrorMode(bool generationMode)
{
    MirrorMode* mirror = new MirrorMode(board, row, col);
    
    if (generationMode) // user chooses to pause each generation
    {
        mirror->simulateEachStep();
    }
    else // user chooses to not pause
    {
        mirror->stimulateToFile();
    }

    delete mirror;
}

// Validate the user input as a short.
unsigned short UserInput::validateShort(std::string message)
{
    unsigned short validNum;
    while (true)
    {
        try
        {
            unsigned short temp;
            std::cout << message;
            std::cin >> temp;

            if (std::cin.fail()) 
            {
                throw std::invalid_argument("Input must be a valid number.");
            }

            validNum = temp;
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    return validNum;
}

// Validate the user input as a int.
float UserInput::validateFloat(std::string message, float& min, float& max)
{
    float validNum;
    while (true)
    {
        try
        {
            float temp;
            std::cout << message;
            std::cin >> temp;

            if (std::cin.fail()) 
            {
                throw std::invalid_argument("Input must be a valid float (ex: '0.4').");
            }
            if (temp < 0.0 || temp > 1.0)
            {
                std::string str = "Input must be between " + std::to_string(min) + " and " + std::to_string(max);
                throw std::invalid_argument(str);
            }

            validNum = temp;
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    return validNum;
}

// Getters
bool** UserInput::getBoard()
{
    return board;
}
unsigned short UserInput::getRow()
{
    return row;
}
unsigned short UserInput::getCol()
{
    return col;
}
float UserInput::getDensity()
{
    return density;
}

// Setters
void UserInput::setRow(unsigned short row)
{
    this->row = row;
}
void UserInput::setCol(unsigned short col)
{
    this->col = col;
}
void UserInput::setDensity(float density)
{
    this->density = density;
}
