#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


using namespace std;

class  clsCurrencyExchangeMainScreen :protected clsScreen
{


private:
    enum enCurrencyMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5

    };

    static short ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowListCurrencies()
    {
        //cout << "\n List Currencies Screen will be here.\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrency()
    {
      // cout << "\n Find Currency Screen will be here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRate()
    {
        // cout << "\n Update Rate Screen will be here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculator()
    {
       // cout << "\n Currency Calculator Screen will be here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    

    static void _GoBackToCurrencyMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowCurrencyMenue();

    }

    static void _PerformCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenueOption)
    {
        
       
        switch (CurrencyMenueOption)
        {
        case enCurrencyMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrencies();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrencyMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrency();
            _GoBackToCurrencyMenue();
            break;
        }


        case enCurrencyMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRate();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrencyMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrencyMenueOptions::eShowMainMenue:
        {

            //do nothing here the main screen will handle it :-) ;

        }
        }


    }



public:


    static void ShowCurrencyMenue()
    {

       
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t Currency Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t Currency Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenueOption((enCurrencyMenueOptions)ReadCurrencyMenueOption());
    }

};

