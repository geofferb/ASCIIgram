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

    /** Get the histogram in string format
     *
     * @return The histogram in ASCII format
     */
    std::string toString() const;

    /** Get the maximum number of bins specified by the user
     *
     * @return The maximum number of bins specified by the user
     */
    int getMaxBins() const;
  };
}