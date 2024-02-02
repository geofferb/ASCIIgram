#pragma once
#include <string>
#include <vector>

namespace ASCIIgram
{
  /**
   * Histogram class
   *
   * This class creates a histogram from a dataset. The number of bins is
   * specified by the user, but fewer bins may be used if the data does not
   * support the requested number of bins.
   * To create a histogram, the user must provide a dataset of integers and a
   * desired number of bins.
   * An ASCII representation of the histogram can be  obtained through
   * toString().
   * The number of bins specified by the user can be obtained through
   * getMaxBins().
   */
  class Histogram
  {
  private:
    int m_maxBins;           // maximum number of bins specified by user
    std::vector<int> m_bins; // bin counts
    int m_nBins;             // number of actual bins used
    int m_min;               // minimum latency
    int m_binSize;           // size of each bin

  public:
    /**
     * Create a histogram from a dataset.
     *
     * @param dataset The dataset to create the histogram from
     * @param maxBins The maximum number of bins to use in the histogram.
     * Fewer bins may be used if the data does not support the requested
     * number of bins.
     */
    Histogram(const std::vector<int> &dataset, const int maxBins);

    /** Return a string representation of the histogram.
     *
     * @param unit Optional unit of the histogram values (e.g. "ms")
     * @param marker The character to use for the histogram bars ('*' by default)
     * @param fieldWidth The width of the field for the bin values (3 by default = 3-digit numbers)
     * @param barScale The scale of the histogram bars (100 by default = 1 symbol per 0.01 of the total count)
     * @return A string representation of the histogram
     */
    std::string toString(std::string unit = "", char marker = '*', int fieldWidth = 3, int barScale = 100) const;

    /** Get the maximum number of bins specified by the user
     *
     * @return The maximum number of bins specified by the user
     */
    int getMaxBins() const;
  };
}