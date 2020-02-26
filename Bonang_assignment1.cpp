#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
// calculateSum - calculates the total amount of nucleotides
float calculateSum(float &length);
// getLength - acts as an accessor to get the length of each string
float getLength(int length);
/* calculateVariance - calculates the top part of the variance equation
   (length - mean ) * (length - mean) given the length and mean*/
float calculateVariance(float length, float mean);
//standardD - calculates the standardDeviation
float standardD(float variance);
// guassianDistribution - conducts all the calculations for Gaussian Distribution.
double guassianDistribution(float mean, float variance);
// generateDnaString - generates a dna string
string generateDnaString(double lengthD, float probA, float probG, float probT, float probC);
// PI - holds the value of pi
const double PI = 3.141592653589793;

int main(int argc, const char * argv[]) {

  // sumNucleotides - holds the total number of nucleotides from file
  float sumNucleotides = 0;

  // countDnaStrings - holds the number of dna strings from file
  float countDnaStrings = 0;

  // count - counts the number of dna nucleotides
  // in the code below, it adds all nucleotides together
  int count = 0;

  // standardDeviation - holds the standard deviation
  float standardDeviation = 0;

  // mean - holds the mean of the total amount of dna strings
  float mean = 0;

  // countEachLength - counts the length of each string
  float countEachLength = 0;

  // countEachLengthAgain - counts the length of each string when opening the
  // file the second time.
  float countEachLengthAgain = 0;

  // calTopVariance - holds the value for the first part in finding the variance.
  // Such as the following: (length - mean)^squared.
  float calTopVariance = 0;

  // calTopVariance - calculates the total variance.
  // Such as the following: (length - mean)^squared / number of dna strings.
  float calTotalVariance = 0;

  // nucBigram - holds the next character of each string in file. Used as a marker
  // that treks through file. Check the first for loop to see that it tracks the
  // index after i (i + 1)
  char nucBigram = '\0';

  // used to count each nucleaotide present in the file
  int countA = 0;
  int countC = 0;
  int countT = 0;
  int countG = 0;

  // holds the probablities of each nucleotide
  float probA = 0;
  float probC = 0;
  float probT = 0;
  float probG = 0;

  // count nucBigram frequency
  int nucBigramFreq = 0;

  // each nucleotide bigram
    // Meaning, // AA, AC, AT, AG
  float nucBigram_AA = 0;
  float nucBigram_AC = 0;
  float nucBigram_AT = 0;
  float nucBigram_AG = 0;
// each nucleotide bigram
    // Meaning, // CA, CC, CT, CG
  float nucBigram_CA = 0;
  float nucBigram_CC = 0;
  float nucBigram_CT = 0;
  float nucBigram_CG = 0;
// each nucleotide bigram
    // Meaning, // TA, TC, TT, TG
  float nucBigram_TA = 0;
  float nucBigram_TC = 0;
  float nucBigram_TT = 0;
  float nucBigram_TG = 0;
// each nucleotide bigram
    // Meaning, // GA, GC, GT, GG
  float nucBigram_GA = 0;
  float nucBigram_GC = 0;
  float nucBigram_GT = 0;
  float nucBigram_GG = 0;
// all hold probablities for each nucleotide bigram
     // starting with 'A'
  float prob_AA = 0;
  float prob_AC = 0;
  float prob_AT = 0;
  float prob_AG = 0;
     // starting with 'C'
  float prob_CA = 0;
  float prob_CC = 0;
  float prob_CT = 0;
  float prob_CG = 0;
    // starting with 'T'
  float prob_TA = 0;
  float prob_TC = 0;
  float prob_TT = 0;
  float prob_TG = 0;
   // starting with 'G'
  float prob_GA = 0;
  float prob_GC = 0;
  float prob_GT = 0;
  float prob_GG = 0;
  // char to hold user choice
  char userChoice = '\0';
  // holds the file name the user inputs
  string userFileName = "";
  // check if the command line arguments are valid
  if(argc < 2)
  {
    cout << "Invalid command line arguments" << endl;
    return 1;
  }

  // fileName holds the file name and is stored in argv
  string fileName = argv[1];
  // inFS - object of ifstream to read from a file
  ifstream inFS;
  // onFS - object of ofstream to write to a file
  ofstream onFS;
  // dnaFromFile - stores all the strings from dnaSequence.txt file
  string dnaFromFile;
  // fileName - holds the file name to write to file.
  string myFileName = "ClarisseBonang.out";
  // currentLine - stores all the string from myFileName
  string currentLine;
  // D - holds the Gaussian distribution or length of each string
  // randomly generated below.
  double D = 0;
  // open the file
  // TODO: do{   //or put below and reset everything
  do{
    //reset variables in case the user selects to to process another file

    // sumNucleotides - holds the total number of nucleotides from file
    sumNucleotides = 0;

    // countDnaStrings - holds the number of dna strings from file
    countDnaStrings = 0;

    // count - counts the number of dna nucleotides
    // in the code below, it adds all nucleotides together
    count = 0;

    // standardDeviation - holds the standard deviation
    standardDeviation = 0;

    // mean - holds the mean of the total amount of dna strings
    mean = 0;

    // countEachLength - counts the length of each string
    countEachLength = 0;

    // countEachLengthAgain - counts the length of each string when opening the
    // file the second time.
    countEachLengthAgain = 0;

    // calTopVariance - holds the value for the first part in finding the variance.
    // Such as the following: (length - mean)^squared.
    calTopVariance = 0;

    // calTopVariance - calculates the total variance.
    // Such as the following: (length - mean)^squared / number of dna strings.
    calTotalVariance = 0;

    // nucBigram - holds the next character of each string in file. Used as a marker
    // that treks through file. Check the first for loop to see that it tracks the
    // index after i (i + 1)
    nucBigram = '\0';

    // used to count each nucleaotide present in the file
    countA = 0;
    countC = 0;
    countT = 0;
    countG = 0;

    // holds the probablities of each nucleotide
    probA = 0;
    probC = 0;
    probT = 0;
    probG = 0;

    // count nucBigram frequency
    nucBigramFreq = 0;

    // each nucleotide bigram
      // Meaning, // AA, AC, AT, AG
    nucBigram_AA = 0;
    nucBigram_AC = 0;
    nucBigram_AT = 0;
    nucBigram_AG = 0;
  // each nucleotide bigram
      // Meaning, // CA, CC, CT, CG
    nucBigram_CA = 0;
    nucBigram_CC = 0;
    nucBigram_CT = 0;
    nucBigram_CG = 0;
  // each nucleotide bigram
      // Meaning, // TA, TC, TT, TG
    nucBigram_TA = 0;
    nucBigram_TC = 0;
    nucBigram_TT = 0;
    nucBigram_TG = 0;
  // each nucleotide bigram
      // Meaning, // GA, GC, GT, GG
    nucBigram_GA = 0;
    nucBigram_GC = 0;
    nucBigram_GT = 0;
    nucBigram_GG = 0;
  // all hold probablities for each nucleotide bigram
       // starting with 'A'
    prob_AA = 0;
    prob_AC = 0;
    prob_AT = 0;
    prob_AG = 0;
       // starting with 'C'
    prob_CA = 0;
    prob_CC = 0;
    prob_CT = 0;
    prob_CG = 0;
      // starting with 'T'
    prob_TA = 0;
    prob_TC = 0;
    prob_TT = 0;
    prob_TG = 0;
     // starting with 'G'
    prob_GA = 0;
    prob_GC = 0;
    prob_GT = 0;
    prob_GG = 0;
    // dnaFromFile - stores all the strings from dnaSequence.txt file
    dnaFromFile = "";
    currentLine = "";
    // D - holds the Gaussian distribution or length of each string
    // randomly generated below.
    D = 0;

  // TODO: RESET variables at top of loop no data type
  inFS.open(fileName);
  // if the file is not open print message
  if(!inFS.is_open())
  {
    cout << "could not open file"<< endl;
    return 1;

  }

  // the while loop reads from the file and prints it out
    while(!inFS.eof())
    {
        inFS >> dnaFromFile;
        if(!inFS.fail())
        {
          // the for loop iterates through each string in the file
          // and utilizes toupper to changes the from lowercase
          // to uppercase.
          for( int i = 0; i < dnaFromFile.length(); ++i)
          {
                dnaFromFile[i] = toupper(dnaFromFile[i]);
                // for every letter after
                nucBigram = toupper(dnaFromFile[i+1]);
                nucBigramFreq = i+1;
              // For every 2 nucleotide there is a nucleotide bigram
              // so, if the next character in the string an odd number(bigram),
              // we can start grouping the nucleotides.
              if(nucBigramFreq % 2 != 0){
                if(dnaFromFile[i] == 'A')
                {
                  count++;
                  countA++;
                  if(nucBigram == 'A')
                  {
                    nucBigram_AA++;
                  }
                  else if (nucBigram == 'C')
                  {
                    nucBigram_AC++;
                  }
                  else if(nucBigram == 'T')
                  {
                    nucBigram_AT++;
                  }
                  else if(nucBigram == 'G')
                  {
                    nucBigram_AG++;
                  }
                }

                else if(dnaFromFile[i] == 'C')
                {
                  count++;
                  countC++;
                  if(nucBigram == 'A')
                  {
                    nucBigram_CA++;
                  }
                  else if (nucBigram == 'C')
                  {
                    nucBigram_CC++;
                  }
                  else if(nucBigram == 'T')
                  {
                    nucBigram_CT++;
                  }
                  else if(nucBigram == 'G')
                  {
                    nucBigram_CG++;
                  }
                }

                else if(dnaFromFile[i] == 'T')
                {
                  count++;
                  countT++;
                  if(nucBigram == 'A')
                  {
                    nucBigram_TA++;
                  }
                  else if (nucBigram == 'C')
                  {
                    nucBigram_TC++;
                  }
                  else if(nucBigram == 'T')
                  {
                    nucBigram_TT++;
                  }
                  else if(nucBigram == 'G')
                  {
                    nucBigram_TG++;
                  }
                }

                else if(dnaFromFile[i] == 'G')
                {
                  count++;
                  countG++;
                  if(nucBigram == 'A')
                  {
                    nucBigram_GA++;
                  }
                  else if (nucBigram == 'C')
                  {
                    nucBigram_GC++;
                  }
                  else if(nucBigram == 'T')
                  {
                    nucBigram_GT++;
                  }
                  else if(nucBigram == 'G')
                  {
                    nucBigram_GG++;
                  }
                }
                else
                 {
                   cout << "Not a nucleotide: A C G T, check file" << endl;
                 }
              }
                 if ( i == dnaFromFile.length() - 1){
                    // FOR EACH string, countEachLength holds the length.
                    countEachLength = getLength(i+1);
                    // sumNucleotides - holds the sum of nucleotides
                    sumNucleotides = sumNucleotides + calculateSum(countEachLength);
                    countDnaStrings++;
              }
           }
        }
    }

  inFS.close();
  mean = float(sumNucleotides)/float(countDnaStrings);
  ifstream inFD;
  string dnaFromFile2 = "";
  inFD.open(fileName);
  // if the file is not open print message
  if(!inFD.is_open())
  {
    cout << "could not open file"<< endl;
    return 1;
  }

  // the following while loop reads from dna file to calculate the variance.
  // Given the mean from the previous loop, we are able to calculate the variance.
  while(!inFD.eof())
  {
    inFD >> dnaFromFile2;
    if(!inFD.fail()){
      for( int i = 0; i < dnaFromFile2.length(); ++i){
         if ( i == dnaFromFile2.length() - 1){
            countEachLengthAgain = getLength(i+1);
            calTopVariance = calTopVariance + calculateVariance(countEachLengthAgain, mean);
          }
      }
   }
}
    // calTotalVariance - Holds the final variance value
    calTotalVariance = calTopVariance/countDnaStrings;
    // standardD - holds the standard deviation value
    standardDeviation = standardD(calTotalVariance);
    // calculates the probablitiy of each nucleotide
    probA = float(countA)/float(count);
    probC = float(countC)/float(count);
    probT = float(countT)/float(count);
    probG = float(countG)/float(count);
    // probablitiy of each nucleotide bigram starting with 'A'
    prob_AA = nucBigram_AA/float(16);
    prob_AC = nucBigram_AC/float(16);
    prob_AG = nucBigram_AG/float(16);
    prob_AT = nucBigram_AT/float(16);
    // probablitiy of each nucleotide bigram starting with 'C'
    prob_CA = nucBigram_CA/float(16);
    prob_CC = nucBigram_CC/float(16);
    prob_CG = nucBigram_CG/float(16);
    prob_CT = nucBigram_CT/float(16);
    // probablitiy of each nucleotide bigram starting with 'T'
    prob_TA = nucBigram_TA/float(16);
    prob_TC = nucBigram_TC/float(16);
    prob_TG = nucBigram_TG/float(16);
    prob_TT = nucBigram_TT/float(16);
    // probablitiy of each nucleotide bigram starting with 'G'
    prob_GA = nucBigram_GA/float(16);
    prob_GC = nucBigram_GC/float(16);
    prob_GG = nucBigram_GG/float(16);
    prob_GT = nucBigram_GT/float(16);
 inFD.close();
 // Now, we must write the information above (probablities)
   // to the file ClarisseBonang.out
 // open the file
 onFS.open(myFileName, ofstream::out | ofstream::app);
 if(!onFS.is_open())
 {
   cout << "could not open file"<< endl;
   return 1;
 }
 if(onFS.is_open())
 {
   onFS << "Clarisse Bonang" << endl;
   onFS << "ID: 2298162" << endl;
   onFS << "Assignment: DNA Strings C++ Review" << endl;
   onFS << "Class: CPSC 350-02" << endl;
   onFS << "File Name: " << fileName << endl;
   onFS << "The Sum of the length of the DNA string is: " << sumNucleotides << endl;
   onFS << "The Mean of the length of the DNA strings is: " << mean << endl;
   onFS << "The variance of the length of the DNA strings: " << calTotalVariance << endl;
   onFS << "The Standard Deviation of the length of DNA strings is " << standardDeviation << endl;
   onFS << "Here is the relative probablitiy of each nucleotide: " << endl;
   onFS << "A:     " << probA << endl;
   onFS << "C:     " << probC << endl;
   onFS << "T:     " << probT << endl;
   onFS << "G:     " << probG << endl;
   onFS << "Here is the relative probablitiy of each nucleotide: " << endl;
// probablitiy of each nucleotide bigram starting with 'A'
   onFS << "AA:    " << prob_AA << endl;
   onFS << "AC:    " << prob_AC << endl;
   onFS << "AG:    " << prob_AG << endl;
   onFS << "AT:    " << prob_AT << endl;
// probablitiy of each nucleotide bigram starting with 'C'
   onFS << "CA:    " << prob_CA << endl;
   onFS << "CC:    " << prob_CC << endl;
   onFS << "CG:    " << prob_CG << endl;
   onFS << "CT:    " << prob_CT << endl;
// probablitiy of each nucleotide bigram starting with 'T'
   onFS << "TA:    " << prob_TA << endl;
   onFS << "TC:    " << prob_TC << endl;
   onFS << "TG:    " << prob_TG << endl;
   onFS << "TT:    " << prob_TT << endl;
// probablitiy of each nucleotide bigram starting with 'G'
   onFS << "GA:    " << prob_GA << endl;
   onFS << "GC:    " << prob_GC << endl;
   onFS << "GG:    " << prob_GG << endl;
   onFS << "GT:    " << prob_GT << endl;

 }
 onFS.close();

 inFS.open(myFileName);
 // if the file is not open print message
 // read from ClarisseBonang.out
 if(!inFS.is_open())
 {
   cout << "could not open file"<< endl;
   return 1;

 }
 // the code below outputs all the information from ClarisseBonang.out
 // such as: probablities of each nucleotide and nucBigram.
 if(inFS.is_open())
 {
   while(getline(inFS, currentLine))
   {
     cout << currentLine << endl;
   }
 }
 inFS.close();
 ofstream onFSR;

 //do{// TODO: put do-while to the top
  // use to append and output to the file
  onFSR.open(myFileName, ofstream::out | ofstream::app);
  if(!onFSR.is_open())
  {
   cout << "could not open file"<< endl;
   return 1;
  }
  if(onFSR.is_open())
   {
    // randomly generate strings of length D and append to file
    for(int i = 0; i < 1000; ++i){
     // D is the length of the string that needs to be read
     // generateDnaString is called to generate the 1000 DNA strings
     D = guassianDistribution(mean, standardDeviation);
     onFSR << generateDnaString(D, probA, probG, probT, probC) << endl;
    }

   }
   onFSR.close();

   cout << "Would you like to process another list? (Y/N): ";
   cin >> userChoice;
   userChoice = toupper(userChoice);
   if(userChoice == 'Y'){
   cout << "Enter the name of the file to read from: ";
   cin >> userFileName;
   fileName = userFileName;
   }
 }while( userChoice == 'Y');
  return 0;
}
float getLength(int length)
{
  return length;
}
float calculateSum(float& sum)
{
  return sum;
}

float calculateVariance(float length, float mean)
{
  // topVariance - holds the value of the first part to calculate
                  // the variance: (length - mean)^2
  float topVariance = 0;

  // Here, we are taking  the length of each string and substracting by the mean.
   topVariance = (length - mean ) * (length - mean);
   return topVariance;
}
float standardD(float variance)
{
  float standardDeviation = 0;
  standardDeviation = sqrt(variance);
  return standardDeviation;
}
double guassianDistribution(float mean, float standardDeviation)
{
  // Box-Muller transform
     // To normalize the random number (ensure it's between 0 and 1)
     // num1 - holds the first random number generated
     double num1 = (double)rand()/RAND_MAX;
     // num2 - holds the first random number generated
     double num2 = (double)rand()/RAND_MAX;
     double C = 0;
     double D = 0;
     C = sqrt(-2 * log(num1)) * cos(2*PI*num2);
     // Preform Gaussian distribution
     D = (standardDeviation*C)+ mean;
     return D;
}
string generateDnaString(double lengthD, float probA, float probG, float probT, float probC)
{

  // The relative frequency of nucleotides will also follow the statistics calculated above.
  double r = 0;
  char nucleotide = '\0';
  string dnaString = "";
  // generate a string that is of lengthD
  for( int i = 0; i < lengthD; ++i)
  {
    r = (double)rand()/RAND_MAX;
    if( r >=0 && r < probA )
     {
          nucleotide = 'A';
     }
     else if( r >= probA && r < (probG + probA))
     {
         nucleotide = 'G';
     }
     else if(r >= (probG + probA) && r < (probT + probG + probT))
     {
          nucleotide = 'T';
      }
      else if(r >= (probT + probG + probT) && r < 1)
      {
           nucleotide = 'C';
      }
      else
      {
         cout << "Error: error in nucleotide selection" << endl;
      }
      // append characters to dnaString
      dnaString += nucleotide;
  }

  return dnaString;
}
