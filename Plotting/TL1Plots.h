#ifndef TL1PLOTS_H
#define TL1PLOTS_H

#include <string>
#include <stdlib.h>

class TL1Plots
{
    public:
        virtual void InitPlots() = 0;
        virtual void Fill(const double & xVal, const double & yVal, const int & pu) = 0;
        virtual void DrawPlots() = 0;

        virtual void SetSample(const std::string & sampleName, const std::string & sampleTitle);
        virtual void SetTrigger(const std::string & triggerName, const std::string & triggerTitle);
        virtual void SetRun(const std::string & run);
        virtual void SetOutName(const std::string & outName);
        virtual void SetOutDir(const std::string & outDir);
        virtual void SetAddMark(const std::string & addMark);
        virtual void SetPuType(const std::vector<std::string> & puType);
        virtual void SetPuBins(const std::vector<int> & puBins);
        void SetColor(TH1 * plot, int pos, int max);
        void SetColor(TGraph * graph, int pos, int max);

    protected:
        std::string GetSampleName() const;
        std::string GetTriggerName() const;
        std::string GetRun() const;
        std::string GetSampleTitle() const;
        std::string GetTriggerTitle() const;
        std::string GetOutName() const;
        std::string GetOutDir() const;
        std::string GetAddMark() const;
        std::vector<std::string> GetPuType() const;
        std::vector<int> GetPuBins() const;

    private:
        std::string fSampleName, fTriggerName, fRun;
        std::string fSampleTitle, fTriggerTitle;
        std::string fOutName, fOutDir;
        std::string fAddMark;
        std::vector<std::string> fPuType;
        std::vector<int> fPuBins;

};

void TL1Plots::SetSample(const std::string & sampleName, const std::string & sampleTitle)
{
    fSampleName = sampleName;
    fSampleTitle = sampleTitle;
}

void TL1Plots::SetTrigger(const std::string & triggerName, const std::string & triggerTitle)
{
    fTriggerName = triggerName;
    fTriggerTitle = triggerTitle;
}

void TL1Plots::SetRun(const std::string & run)
{
    fRun = run;
}

void TL1Plots::SetOutName(const std::string & outName)
{
    fOutName = outName;
}

void TL1Plots::SetOutDir(const std::string & outDir)
{
    std::system(Form("mkdir -p %s",outDir.c_str()));
    fOutDir = outDir;
}

void TL1Plots::SetAddMark(const std::string & addMark)
{
    fAddMark = addMark;
}

void TL1Plots::SetPuType(const std::vector<std::string> & puType)
{
    fPuType = puType;
}

void TL1Plots::SetPuBins(const std::vector<int> & puBins)
{
    fPuBins = puBins;
}

void TL1Plots::SetColor(TH1 * plot, int pos, int max)
{
    double modifier(0.15), colorIndex;
    int colour(1);
    double fraction = (double)(pos)/(double)(max-1);

    if( pos > max-1 || pos < 0 || max < 0 ) colour = 1;
    else
    {
        colorIndex = (fraction * (1.0-2.0*modifier) + modifier) * gStyle->GetNumberOfColors();
        colour = gStyle->GetColorPalette(colorIndex);
    }
    plot->SetLineColor(colour);
    plot->SetMarkerColor(colour);
}

void TL1Plots::SetColor(TGraph * graph, int pos, int max)
{
    double modifier(0.15), colorIndex;
    int colour(1);
    double fraction = (double)(pos)/(double)(max-1);

    if( pos > max-1 || pos < 0 || max < 0 ) colour = 1;
    else
    {
        colorIndex = (fraction * (1.0-2.0*modifier) + modifier) * gStyle->GetNumberOfColors();
        colour = gStyle->GetColorPalette(colorIndex);
    }
    graph->SetLineColor(colour);
    graph->SetMarkerColor(colour);
    graph->SetFillColor(colour);
}

std::string TL1Plots::GetSampleName() const
{
    return fSampleName;
}

std::string TL1Plots::GetTriggerName() const
{
    return fTriggerName;
}

std::string TL1Plots::GetRun() const
{
    return fRun;
}

std::string TL1Plots::GetSampleTitle() const
{
    return fSampleTitle;
}

std::string TL1Plots::GetTriggerTitle() const
{
    return fTriggerTitle;
}

std::string TL1Plots::GetOutName() const
{
    return fOutName;
}

std::string TL1Plots::GetOutDir() const
{
    return fOutDir;
}

std::string TL1Plots::GetAddMark() const
{
    return fAddMark;
}

std::vector<std::string> TL1Plots::GetPuType() const
{
    return fPuType;
}

std::vector<int> TL1Plots::GetPuBins() const
{
    return fPuBins;
}

#endif
