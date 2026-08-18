#include "ROOT/RVec.hxx"
#include "RtypesCore.h"
#define BMNHYPNUCLPAIR_H

#include <ROOT/RDataFrame.hxx>
#include <Math/LorentzVector.h>
#include <Math/PtEtaPhiE4D.h>
#include <vector>
#include <string>
#include <typeinfo>
#include <cxxabi.h>

using namespace ROOT;
using namespace ROOT::Math;
using namespace ROOT::RDF;

template<typename T>
using vector1d_t = ROOT::VecOps::RVec<T>;
template<typename T>
using vector2d_t = ROOT::VecOps::RVec<vector1d_t<T>>;

using vector1d_I = vector1d_t<Int_t>;
using vector1d_U = vector1d_t<UInt_t>;
using vector1d_S = vector1d_t<Short_t>;
using vector1d_F = vector1d_t<Float_t>;
using vector2d_F = vector2d_t<Float_t>;

using fourVector=LorentzVector<PtEtaPhiE4D<double>>;

// for dEdx
std::vector<TGraph *> g1_a_lo_runid_vec;
std::vector<TGraph *> g1_b_lo_runid_vec;
std::vector<TGraph *> g1_a_up_runid_vec;
std::vector<TGraph *> g1_b_up_runid_vec;
TGraph *g1_a_lo_plane = nullptr;
TGraph *g1_b_lo_plane = nullptr;
TGraph *g1_a_up_plane = nullptr;
TGraph *g1_b_up_plane = nullptr;
TGraph *g1_a_b_uTol = nullptr;
Double_t a_dedx_calib, b_dedx_calib;

std::map<int, std::vector<int>> tof400_strips_to_exclude{ {0, {39, 40, 41, 42}}, {6, {19}}, {8, {29,30,31}}, {9, {15,16,26,27,28}},{12, {40}}, {16, {7, 8, 9, 10, 11, 12, 13, 14, 16, 19, 20, 21, 22, 23, 24, 25, 37}}, {18, {4, 13, 14, 15}}, {19, {35, 37}} };
std::map<int, std::vector<int>> tof700_strips_to_exclude{ {2, {25,26,}}, {3, {31}}, {5, {31}}, {6, {31}}, {8, {7,11,15,31}}, {9, {31}}, {10, {28,31}}, {12, {31}}, {13, {18,19,20,21,22,23,24,25,26,27,228,29,30,31}}, {14, {31}}, {16, {31}}, {17, {31}}, {18, {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,31}}, {19, {31}}, {20,{31}}, {21, {13,14,15,23,24,25,27,30,31}}, {22, {31}}, {24, {31}}, {25, {31}}, {26, {6, 31}}, {27, {31}}, {28, {31}}, {29, {8,31}}, {30, {15,17,31}}, {31, {31}}, {32, {31}}, {33,{22,23,24,25,31}}, {34, {24,25,31}}, {35,{31}}, {36, {31}}, {37, {31}}, {38, {31}}, {39, {31}}, {40, {1,2,3,4,5,6,7,8,9,11,17,18,19,20,26,27,31}}, {45, {11,12,13,15}}, {49, {15}}, {52, {3}}, {55, {8,9}}, {57, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}} };

std::vector<int> physical_runs{6667, 6668, 6669, 6670, 6671, 6672, 6673, 6674, 6675, 6676, 6677, 6678, 6679, 6680, 6681, 6683, 6684, 6685, 666, 6687, 6689, 6690, 6691, 6692, 6694, 6695, 6696, 6698, 6699, 6732, 6733, 6734, 6737, 6738, 6739, 6740, 6745, 6752, 6753, 6760, 6761, 6765, 6766, 6767, 6768, 6769, 6771, 6772, 6773, 6774, 6779, 6780, 6782, 6783, 6785, 6786, 6788, 6794, 6795, 6797, 6799, 6800, 6803, 6815, 6816, 6817, 6818, 6819, 6820, 6821, 6822, 6879, 6882, 6883, 6884, 6886, 6887, 6889, 6891, 6900, 6901, 6902, 6903, 6904, 6905, 6906, 6907, 6908, 6909, 6910, 6911, 6915, 6916, 6918, 6919, 6920, 6921, 6923, 6924, 6926, 6927, 6928, 6929, 6930, 6931, 6932, 6933, 6934, 6935, 6936, 6937, 6939, 6940, 6968, 6970, 6972, 6973, 6975, 6976, 6977, 6978, 6979, 6980, 6981, 6982, 6983, 6984, 6990, 6991, 6992, 6993, 6994, 6995, 6997, 6998, 6999, 7000, 7002, 7003, 7004, 7005, 7006, 7008, 7009, 7010, 7011, 7012, 7030, 7031, 7032, 7033, 7034, 7035, 7037, 7038, 7040, 7041, 7042, 7043, 7044, 7046, 7047, 7048, 7049, 7050, 7051, 7052, 7053, 7054, 7055, 7056, 7075, 7076, 7077, 7078, 7081, 7082, 7083, 7084, 7086, 7087, 7091, 7092, 7093, 7094, 7096, 7097, 7098, 7100, 7101, 7102, 7103, 7104, 7125, 7126, 7127, 7128, 7129, 7130, 7131, 7132, 7133, 7135, 7136, 7137, 7138, 7146, 7149, 7150, 7151, 7154, 7155, 7156, 7157, 7159, 7160, 7161, 7162, 7163, 7164, 7165, 7166, 7167, 7168, 7173, 7174, 7175, 7176, 7177, 7178, 7179, 7180, 7181, 7182, 7184, 7186, 7187, 7188, 7191, 7192, 7193, 7194, 7195, 7200, 7202, 7203, 7205, 7206, 7207, 7208, 7209, 7211, 7212, 7213, 7214, 7215, 7216, 7217, 7218, 7219, 7220, 7223, 7225, 7255, 7258, 7261, 7263, 7265, 7267, 7268, 7269, 7271, 7272, 7274, 7276, 7278, 7279, 7281, 7284, 7286, 7288, 7290, 7291, 7312, 7313, 7320, 7321, 7322, 7323, 7325, 7326, 7327, 7328, 7337, 7342, 7343, 7344, 7345, 7346, 7348, 7349, 7351, 7352, 7353, 7354, 7355, 7356, 7357, 7358, 7359, 7361, 7363, 7364, 7365, 7367, 7369, 7374, 7376, 7377, 7378, 7379, 7380, 7381, 7382, 7386, 7387, 7388, 7389, 7390, 7391, 7392, 7393, 7395, 7396, 7397, 7398, 7399, 7400, 7401, 7402, 7403, 7405, 7406, 7408, 7409, 7410, 7411, 7412, 7413, 7414, 7415, 7417, 7418, 7419, 7421, 7422, 7423, 7425, 7427, 7428, 7429, 7431, 7432, 7433, 7434, 7435, 7437, 7439, 7440, 7441, 7442, 7444, 7445, 7446, 7447, 7449, 7451, 7452, 7453, 7454, 7455, 7456, 7457, 7458, 7460, 7461, 7469, 7471, 7472, 7473, 7474, 7477, 7478, 7480, 7481, 7482, 7483, 7484, 7487, 7488, 7489, 7490, 7491, 7492, 7493, 7495, 7497, 7498, 7500, 7501, 7502, 7513, 7514, 7515, 7517, 7519, 7520, 7521, 7528, 7529, 7530, 7531, 7532, 7533, 7534, 7537, 7538, 7539, 7542, 7543, 7545, 7546, 7547, 7549, 7550, 7551, 7552, 7553, 7554, 7564, 7565, 7566, 7567, 7569, 7570, 7572, 7573, 7574, 7575, 7577, 7579, 7581, 7584, 7585, 7586, 7587, 7590, 7591, 7592, 7596, 7597, 7599, 7600, 7604, 7605, 7606, 7607, 7608, 7609, 7611, 7612, 7613, 7622, 7623, 7625, 7626, 7627, 7628, 7630, 7631, 7633, 7634, 7635, 7636, 7638, 7639, 7640, 7641, 7643, 7644, 7645, 7646, 7647, 7649, 7655, 7656, 7657, 7659, 7660, 7662, 7663, 7664, 7665, 7666, 7668, 7669, 7670, 7671, 7673, 7674, 7675, 7676, 7677, 7678, 7679, 7681, 7682, 7684, 7685, 7687, 7688, 7689, 7690, 7692, 7693, 7694, 7696, 7698, 7700, 7701, 7702, 7703, 7704, 7705, 7710, 7712, 7713, 7714, 7715, 7716, 7717, 7718, 7721, 7723, 7724, 7725, 7726, 7727, 7728, 7729, 7730, 7732, 7733, 7734, 7735, 7736, 7737, 7751, 7752, 7753, 7755, 7756, 7761, 7762, 7763, 7764, 7766, 7767, 7768, 7769, 7771, 7772, 7775, 7776, 7778, 7779, 7780, 7781, 7783, 7784, 7785, 7786, 7788, 7789, 7790, 7791, 7794, 7795, 7796, 7797, 7798, 7801, 7802, 7803, 7814, 7816, 7819, 7821, 7824, 7825, 7828, 7829, 7830, 7831, 7832, 7834, 7835, 7836, 7842, 7843, 7845, 7846, 7847, 7848, 7850, 7851, 7852, 7853, 7855, 7856, 7857, 7858, 7859, 7865, 7868, 7869, 7870, 7871, 7873, 7874, 7876, 7877, 7878, 7880, 7882, 7883, 7884, 7885, 7886, 7887, 7890, 7891, 7892, 7893, 7894, 7896, 7897, 7898, 7899, 7900, 7901, 7903, 7904, 7905, 7906, 7907, 7908, 7910, 7911, 7912, 7913, 7914, 7931, 7932, 7933, 7935, 7937, 7938, 7939, 7941, 7942, 7944, 7948, 7949, 7950, 7952, 7954, 7955, 7957, 7958, 7960, 7961, 7962, 7963, 7965, 7966, 7967, 7975, 7977, 7978, 7979, 7981, 7982, 7986, 7988, 7989, 7990, 7991, 7992, 7995, 7996, 7997, 7998, 7999, 8000, 8001, 8002, 8004, 8005, 8006, 8007, 8008, 8009, 8013, 8014, 8015, 8016, 8018, 8020, 8021, 8022, 8023, 8026, 8027, 8028, 8029, 8030, 8031, 8032, 8033, 8038, 8039, 8040, 8041, 8042, 8044, 8045, 8046, 8047, 8048, 8050, 8051, 8052, 8053, 8055, 8056, 8057, 8058, 8059, 8061, 8063, 8064, 8065, 8066, 8068, 8069, 8070, 8071, 8072, 8074, 8075, 8076, 8077, 8079, 8080, 8081, 8082, 8084, 8086, 8087, 8088, 8089, 8090, 8097, 8100, 8101, 8102, 8104, 8106, 8108, 8109, 8110, 8111, 8112, 8113, 8115, 8116, 8117, 8118, 8119, 8121, 8122, 8123, 8124, 8129, 8130, 8131, 8133, 8137, 8138, 8139, 8140, 8141, 8142, 8144, 8156, 8157, 8158, 8159, 8160, 8161, 8162, 8165, 8166, 8167, 8168, 8169, 8170, 8173, 8174, 8175, 8176, 8177, 8180, 8183, 8184, 8186, 8188, 8190, 8191, 8192, 8193, 8195, 8196, 8198, 8199, 8201, 8202, 8203, 8204, 8205, 8206, 8207, 8208, 8209, 8210, 8211, 8212, 8213, 8215, 8217, 8219, 8220, 8221, 8228, 8229, 8230, 8231, 8235, 8236, 8238, 8239, 8240, 8242, 8244, 8245, 8246, 8247, 8248, 8250, 8251, 8253, 8254, 8255, 8256, 8257, 8258, 8265, 8266, 8267, 8268, 8270, 8271, 8273, 8274, 8275, 8276, 8277, 8278, 8279, 8281, 8284, 8286, 8287, 8288, 8289, 8290, 8292, 8293, 8294, 8295, 8297, 8298, 8299, 8300, 8305, 8306};
std::vector<int> bad_runs{7313, 7415, 7417, 7435, 7469, 7517, 7519, 7520, 7537, 7575, 7604, 7630, 7657, 7659, 7679, 7681, 7705, 7735, 7843, 7847, 7848, 7850, 7851, 7852, 7853, 7855, 7856, 7857, 7858, 7859, 7865, 7868, 7907, 7931, 7932, 7933, 7935, 7937, 7938, 7939, 7954, 7955, 8031, 8032, 8033, 8115, 8121, 8167, 8201, 8204, 8205, 8208, 8209, 8210, 8211, 8212, 8213, 8215, 8247, 8265, 8266, 8267, 8281, 8289};
const std::vector<int> arrUsedHits_50{0, 0, 0, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11};

BmnFieldMap* magField{nullptr};

double Poly3Poly3(double* xx, double* pp){
      double threshold = pp[0];
      double a_pol3 = pp[1];
      double b_pol3 = pp[2];
      double c_pol3 = pp[3];
      double d_pol3 = pp[4];
      double a_pol3_2 = pp[5];
      double b_pol3_2 = pp[6];
      double c_pol3_2 = pp[7];
      double d_pol3_2 = pp[8];
      
      return xx[0] < threshold ? a_pol3*pow(xx[0],3) + b_pol3*pow(xx[0],2) + c_pol3*pow(xx[0],1) + d_pol3 : a_pol3_2*pow(xx[0],3) + b_pol3_2*pow(xx[0],2) + c_pol3_2*pow(xx[0],1) + d_pol3_2;
}

double SkewGaus(double* xx, double* pp){
    auto A = pp[0];
    auto mean = pp[1];
    auto sigma = pp[2];
    auto alpha = pp[3];
    auto norm = A / (sqrt(2. * TMath::Pi()) * sigma);
    auto arg = (xx[0] - mean) / sigma;
    auto phi = TMath::Gaus(arg, 0.0, 1.0, true);
    auto Phi = 0.5 * (1 + std::erf(alpha * arg / std::sqrt(2)));
    
    return norm * phi * Phi;
}

double Poly3Gaus(double* xx, double* pp){
    double threshold = pp[0];
    double amplitude = pp[1];
    double mean = pp[2];
    double sigma = pp[3];
    double a_pol3 = pp[4];
    double b_pol3 = pp[5];
    double c_pol3 = pp[6];
    double d_pol3 = pp[7];
    double l = pp[8];
    double norm = amplitude / (sqrt(2. * TMath::Pi()) * sigma);
    double arg = (xx[0] - mean) / sigma;
    double smallphi = TMath::Gaus(arg, 0.0, 1.0, true);

    return xx[0] < threshold ? a_pol3*pow(xx[0],3) + b_pol3*pow(xx[0],2) + c_pol3*pow(xx[0],1) + d_pol3 : norm * smallphi + l;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////data function/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TChain* makeChain(string& filename, const char* treename) {
  cout << "Adding files to chain:" << endl;
  TChain *chain = new TChain(treename);
  if (filename.rfind(".root") < filename.size())
    chain->Add(filename.data());
  else {
    TFileCollection fc("fc", "", filename.c_str());
    chain->AddFileInfoList((TCollection*)fc.GetList());
  }
  chain->ls();
  return chain;
}

//convert to RVec<Float_t> (vectro1d_F)
vector1d_F ConvertToFloat_t(const RVec<double>& vec)
try {
  return vector1d_F(vec.begin(), vec.end());
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

// global track
enum class TrackParamConvert { Pq, P, Pt, Phi, Eta, Pz, Dedx, Q};

auto GlobalTrackParamFloat(TrackParamConvert param) {
  return [param](const RVec<BmnGlobalTrack> tracks) -> vector1d_F {
    vector1d_F result;
    result.reserve(tracks.size());
    
    for (auto track:tracks) {
      auto* par = track.GetParamFirst();
      if (!par) {
          result.push_back(-999.0f);
          continue;
      }
      switch (param) {
        case TrackParamConvert::Pq:
          result.push_back(1.0 / par->GetQp());
          break;
        case TrackParamConvert::P:
          result.push_back(std::abs(1.0 / par->GetQp()));
          break;
        case TrackParamConvert::Pt: {
          TVector3 mom;
          par->Momentum(mom);
          result.push_back(mom.Pt());
          break;
        }
        case TrackParamConvert::Phi: {
          TVector3 mom;
          par->Momentum(mom);
          result.push_back(mom.Phi());
          break;
        }
        case TrackParamConvert::Eta: {
          TVector3 mom;
          par->Momentum(mom);
          result.push_back(mom.Eta());
          break;
        }
        case TrackParamConvert::Pz: {
          TVector3 mom;
          par->Momentum(mom);
          result.push_back(mom.Pz());
          break;
        }
        case TrackParamConvert::Dedx: {
          result.push_back(track.GetdQdNLower());
          break;
        }
        case TrackParamConvert::Q: {
          result.push_back(track.GetZ());
          break;
        }
      }
    }
    return result;
  };
}

vector1d_S recCharge(const RVec<BmnGlobalTrack> tracks)
try {
  vector1d_S charge;
  for (auto track:tracks) {
    int q = track.GetParamFirst()->GetQp() > 0 ? 1 : -1;
    charge.push_back(q);
  }
  return charge;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

//DCA gl tr
enum class DcaTypeConvert { X, Y, Z, R };

const auto recDcaXYZR = [](DcaTypeConvert type) {
  return [type](const RVec<BmnGlobalTrack> tracks, const CbmVertex vtx) {
    vector1d_F dca;
    dca.reserve(tracks.size());
    
    float vx = vtx.GetX();
    float vy = vtx.GetY();
    float vz = vtx.GetZ();
    
    for (auto track : tracks) {
      auto* par = track.GetParamFirst();
      if (!par) {
        dca.push_back(-999.0f);
        continue;
      }
      switch (type) {
        case DcaTypeConvert::X: dca.push_back(par->GetX() - vx); break;
        case DcaTypeConvert::Y: dca.push_back(par->GetY() - vy); break;
        case DcaTypeConvert::Z: dca.push_back(par->GetZ() - vz); break;
        case DcaTypeConvert::R: {
          float dx = par->GetX() - vx;
          float dy = par->GetY() - vy;
          dca.push_back(std::hypot(dx, dy));
          break;
        }
      }
    }
    return dca;
  };
};

vector2d_F covMatrix(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector2d_F covariance_matrix;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);
    auto* par = track.GetParamFirst();
    covariance_matrix.emplace_back();
    for( int i=0; i<5; ++i ){
      for( int j=0; j<=i; ++j ){
        covariance_matrix.back().push_back( par->GetCovariance(i, j) );
      }
    }
    // Lower triangle of the symmetric covariance matrix
    // C[x, y, tx, ty, Qp]
    // { c_00, c1[0..1], c2[0..2], ... c4[0..4] }
  }
  return covariance_matrix;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F globalTrackCovMatrix(RVec<BmnGlobalTrack> global_tracks)
try {
  vector2d_F covariance_matrix;
  for (auto& global_track : global_tracks) {
    auto* par = global_track.GetParamFirst();
    covariance_matrix.emplace_back();
    for( int i=0; i<5; ++i ){
      for( int j=0; j<=i; ++j ){
        covariance_matrix.back().push_back( par->GetCovariance(i, j) );
      }
    }
    // Lower triangle of the symmetric covariance matrix
    // C[x, y, tx, ty, Qp]
    // { c_00, c1[0..1], c2[0..2], ... c4[0..4] }
  }
  return covariance_matrix;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

float determinant3x3( const std::array<std::array<float, 3>, 3>& matrix ) try {
  auto x_0 = matrix[0][0] * ( matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]  );
  auto x_1 = matrix[0][1] * ( matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]  );
  auto x_2 = matrix[0][2] * ( matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]  );

  return x_0 - x_1 + x_2;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

std::array<float, 3> cramerFieldSolver3x3( std::array<float, 3> field, std::array<float, 3> coordinate ) try {
  // Solving the system of equation to extract parameters of quadratic extrapolation of the magnetic field
  // Ax = B
  // xi = detAi / detA
  std::array<std::array<float, 3>, 3> A;
  A[0] = {1.0f, 1.0f, 1.0f };
  A[1] = { coordinate[0], coordinate[1], coordinate[2] };
  A[2] = { coordinate[0]*coordinate[0], coordinate[1]*coordinate[1], coordinate[2]*coordinate[2] };

  auto A0 = A;
  A0[0] = field;
  auto A1 = A;
  A1[1] = field;
  auto A2 = A;
  A2[2] = field;

  auto detA = determinant3x3( A );
  auto detA0 = determinant3x3( A0 );
  auto detA1 = determinant3x3( A1 );
  auto detA2 = determinant3x3( A2 );

  auto p0 = detA0 / detA;
  auto p1 = detA1 / detA;
  auto p2 = detA2 / detA;

  return {p0, p1, p2};
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F magneticField(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks, RVec<CbmStsHit> sts_hits)
try {
  vector2d_F magnetic_field;
  for (auto& global_track : global_tracks ) {

    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);

    std::array<float, 3> hit_z;
    std::array<float, 3> hit_bx;
    std::array<float, 3> hit_by;
    std::array<float, 3> hit_bz;

    for( int i=0; i<3; ++i ){
      // It seems size of the hitmap cannot be less than 4, but just to be safe
      if( i > track.GetStsHits()->GetSize() )
        magnetic_field.push_back( std::vector<float>(10, 0.0f) );

      auto sts_idx = track.GetStsHits()->At(i);
      auto x = sts_hits.at(sts_idx).GetX();
      auto y = sts_hits.at(sts_idx).GetY();
      auto z = sts_hits.at(sts_idx).GetZ();

      hit_z.at(i) = z;
      hit_bx.at(i) = magField->GetBx( x, y, z ); // kGs
      hit_by.at(i) = magField->GetBy( x, y, z ); // kGs
      hit_bz.at(i) = magField->GetBz( x, y, z ); // kGs
    }

    auto parameters_bx = cramerFieldSolver3x3( hit_bx, hit_z );
    auto parameters_by = cramerFieldSolver3x3( hit_by, hit_z );
    auto parameters_bz = cramerFieldSolver3x3( hit_bz, hit_z );

    magnetic_field.emplace_back();
    for( const auto& c : parameters_bx )
      magnetic_field.back().push_back( c );
    for( const auto& c : parameters_by )
      magnetic_field.back().push_back( c );
    for( const auto& c : parameters_bz )
      magnetic_field.back().push_back( c );
    magnetic_field.back().push_back( 0.0 ); // z0
  }
  return magnetic_field;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

Int_t GetNHits_Convert(const TClonesArray& hits)
try {
    Int_t total_hits = hits.GetEntriesFast();
    return total_hits;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F stsTrackParameters(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector2d_F parameters;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);

    auto* par = track.GetParamFirst();
    parameters.emplace_back();
    parameters.back().push_back( par->GetX() );
    parameters.back().push_back( par->GetY() );
    parameters.back().push_back( par->GetZ() );
    parameters.back().push_back( par->GetTx() );
    parameters.back().push_back( par->GetTy() );
    parameters.back().push_back( par->GetQp() );
  }
  return parameters;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F FakeTrackParam(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector1d_F parameters;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);
    parameters.push_back( track.GetB() );
  }
  return parameters;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F globalTrackParameters(RVec<BmnGlobalTrack> global_tracks)
try {
  vector2d_F parameters;
  for (auto& global_track : global_tracks) {
    auto* par = global_track.GetParamFirst();
    parameters.emplace_back();
    parameters.back().push_back( par->GetX() );
    parameters.back().push_back( par->GetY() );
    parameters.back().push_back( par->GetZ() );
    parameters.back().push_back( par->GetTx() );
    parameters.back().push_back( par->GetTy() );
    parameters.back().push_back( par->GetQp() );
  }
  return parameters;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F trParamFirst(RVec<BmnGlobalTrack> global_tracks)
try {
  vector2d_F parameters;
  for (auto& global_track : global_tracks) {
    auto* par = global_track.GetParamFirst();
    parameters.emplace_back();
    parameters.back().push_back( par->GetX() );
    parameters.back().push_back( par->GetY() );
    parameters.back().push_back( par->GetZ() );
    parameters.back().push_back( par->GetTx() );
    parameters.back().push_back( par->GetTy() );
    parameters.back().push_back( par->GetQp() );
  }
  return parameters;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F trParamLast(RVec<BmnGlobalTrack> global_tracks)
try {
  vector2d_F parameters;
  for (auto& global_track : global_tracks) {
    auto* par = global_track.GetParamLast();
    parameters.emplace_back();
    parameters.back().push_back( par->GetX() );
    parameters.back().push_back( par->GetY() );
    parameters.back().push_back( par->GetZ() );
    parameters.back().push_back( par->GetTx() );
    parameters.back().push_back( par->GetTy() );
    parameters.back().push_back( par->GetQp() );
  }
  return parameters;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F BeamTrackParameters(RVec<BmnTrack> beam_tracks)
try {
  vector2d_F parameters;
  for (auto& beam_track : beam_tracks) {
    auto *par = beam_track.GetParamLast();
    parameters.emplace_back();
    parameters.back().push_back( par->GetX() );
    parameters.back().push_back( par->GetY() );
    parameters.back().push_back( par->GetZ() );
    parameters.back().push_back( par->GetTx() );
    parameters.back().push_back( par->GetTy() );
    parameters.back().push_back( par->GetQp() );
  }
  return parameters;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector<fourVector> stsTrackMomentum(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector<fourVector> momenta;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);
    auto *par = track.GetParamFirst();
    TVector3 mom;
    par->Momentum(mom);
    momenta.push_back({mom.Pt(),mom.Eta(),mom.Phi(),0});
  }
  return momenta;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F stsTrackChi2Ndf(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector1d_F vec_chi2;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);

    auto chi2 = track.GetChi2();
    auto ndf = track.GetNDF();

    vec_chi2.push_back( chi2/ndf );
  }
  return vec_chi2;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_I stsTrackNdf(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector1d_I vec_ndf;
  for (auto& global_track : global_tracks) {
        auto idx = global_track.GetGemTrackIndex();
        auto track = tracks.at(idx);

    auto ndf = track.GetNDF();

    vec_ndf.push_back( ndf );
  }
  return vec_ndf;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_I stsTrackNhits(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector1d_I vec_ndf;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);

    auto ndf = track.GetNStsHits();

    vec_ndf.push_back( ndf );
  }
  return vec_ndf;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

/// BeamHit
enum class ComponentXYZ_Convert { X, Y, Z };

auto beamHitXYZ(ComponentXYZ_Convert type) {
  return [type](const RVec<BmnSiBTHit> tracks) -> vector1d_F {
    vector1d_F out_vec;
    out_vec.reserve(tracks.size());
    for (auto track:tracks){
      switch (type) {
        case ComponentXYZ_Convert::X: out_vec.push_back(track.GetX()); break;
        case ComponentXYZ_Convert::Y: out_vec.push_back(track.GetY()); break;
        case ComponentXYZ_Convert::Z: out_vec.push_back(track.GetZ()); break;
      }
    }
    return out_vec;
  };
}

vector1d_I beamHitStation(const RVec<BmnSiBTHit> tracks)
try {
  vector1d_I _station;
  for (auto track:tracks)
    _station.push_back(track.GetStation());
  return _station;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_I beamHitIndex(const RVec<BmnSiBTHit> tracks)
try {
  vector1d_I _index;
  for (auto track:tracks)
    _index.push_back(track.GetIndex());
  return _index;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector<XYZVector> recPosLast(const RVec<BmnGlobalTrack> tracks)
try {
  vector<XYZVector> pos;
  for (auto track:tracks){
    auto par=track.GetParamLast();
    pos.push_back({par->GetX(), par->GetY(), par->GetZ()});
  }
  return pos;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_I TofHitPlane(const RVec<BmnTofHit>& tofHits)
try
{
  // print.qf()
  vector1d_I hit_mod_num;
  hit_mod_num.reserve(tofHits.size());
  for( const auto& hit : tofHits )
  {
    int mod = ((hit.GetDetectorID() & 0x0000FF00) >> 8) - 1;
    hit_mod_num.push_back(mod);
  }
  return hit_mod_num;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_I TofHitStrip(const RVec<BmnTofHit>& tofHits)
try
{
  vector1d_I hit_strip_num;
  hit_strip_num.reserve(tofHits.size());
  for( const auto& hit : tofHits )
  {
    int strip = ((hit.GetDetectorID() & 0x000000FF)) - 1;
    hit_strip_num.push_back(strip);
  }
  return hit_strip_num;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}


//=========== debug functions ==================
vector1d_I trTofHitPlane(const RVec<int> fHitIndex, const RVec<int>& tofHits)
try
{
  vector1d_I hit_mod_num(fHitIndex.size(), -1);
  for(int i = 0; i < fHitIndex.size(); ++i)
  {
    if (fHitIndex.at(i) < 0) continue;
    hit_mod_num.at(i) = tofHits.at(fHitIndex.at(i));
  }
  return hit_mod_num;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_I trTofHitStrip(const RVec<int> fHitIndex, const RVec<int>& tofHits)
try
{
  vector1d_I hit_strip_num(fHitIndex.size(), -1);
  for(int i = 0; i < fHitIndex.size(); ++i)
  {
    if (fHitIndex.at(i) < 0) continue;
    hit_strip_num.at(i) = tofHits.at(fHitIndex.at(i));
  }
  return hit_strip_num;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F trTofT(ROOT::RVecF vec_P, ROOT::RVecF vec_T, ROOT::VecOps::RVec<int> hit_num)
try {
  vector1d_F vec_T_Tp{};
  vec_T_Tp.reserve(vec_P.size());
      for( int i=0; i<vec_P.size(); ++i ){
      if(hit_num.at(i)==-1){
          vec_T_Tp.push_back(-999);
          continue;
      }
      vec_T_Tp.push_back(vec_T.at(hit_num.at(i)));
      }
  return vec_T_Tp;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
};

vector1d_F trTofL(ROOT::RVecF vec_P, ROOT::RVecF vec_tof, ROOT::VecOps::RVec<int> hit_num)
try {
  vector1d_F vec_tof_Tp{};
  vec_tof_Tp.reserve(vec_P.size());
      for( int i=0; i<vec_P.size(); ++i ){
      if(hit_num.at(i)==-1){
          vec_tof_Tp.push_back(-999);
          continue;
      }
      vec_tof_Tp.push_back(vec_tof.at(hit_num.at(i)));
      }
  return vec_tof_Tp;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
};

//матчинг глобал трека к стрипу и плейну в tof
auto TofStripNumberToGlTr(int _TofType){
  return [_TofType](const vector1d_F& vec_P, const vector1d_I& hit_num, const vector1d_I& num_plane, const vector1d_I& num_strip) -> vector1d_I {
    try {
      vector1d_I vec_strip_tr;
      vec_strip_tr.reserve(vec_P.size());
      
      for (int i = 0; i < vec_P.size(); ++i) {
        if (hit_num.at(i) == -1) {
            vec_strip_tr.push_back(-999);
            continue;
        }

        int plane_num = num_plane.at(i);
        int strip_num = num_strip.at(i);
        
        if(_TofType==400){
          vec_strip_tr.push_back(plane_num * 48 + strip_num);
        }else if(_TofType==700){
          if(plane_num<41){
            vec_strip_tr.push_back(plane_num*32+strip_num);
          }else{
            vec_strip_tr.push_back(1312+(plane_num-41)*16+strip_num);
          }
        }
      }
      return vec_strip_tr;
    } catch (const std::exception& e) {
      std::cout << __func__ << ": " << e.what() << std::endl;
      throw;
    }
  };
}


auto TofHitTCorrToGlTr(TH2D* h2_run_calib, TH2D* h2_run_strip_calib) {
  return [h2_run_calib, h2_run_strip_calib](const vector1d_F& vec_T, const UInt_t run_id, const vector1d_I& strip_num, const vector1d_F& vec_P, const vector1d_I& hit_num) -> vector1d_F {
    try {
      vector1d_F vec_Tcorr;
      vec_Tcorr.reserve(vec_P.size());
      
      const float scale = 1000.0f;
      
      for (int i = 0; i < vec_P.size(); ++i) {
        if (hit_num.at(i) == -1) {
          vec_Tcorr.push_back(-999.0f);
          continue;
        }
      
        int idx = hit_num.at(i);
        int strip = strip_num.at(i);
      
        if(h2_run_calib==nullptr || h2_run_strip_calib==nullptr){
          vec_Tcorr.push_back(vec_T.at(idx));
          continue;
        }

        double binx_run = h2_run_calib->GetXaxis()->FindBin((double)run_id);
        double binx_run_strip = h2_run_strip_calib->GetXaxis()->FindBin((double)run_id);
        double biny = strip + 1; 
        double T_run_calib = h2_run_calib->GetBinContent(binx_run, biny)/scale;
        double T_run_strip_calib = h2_run_strip_calib->GetBinContent(binx_run_strip, biny)/scale;

        vec_Tcorr.push_back(vec_T.at(idx) + T_run_calib + T_run_strip_calib);
      }
      return vec_Tcorr;
    } catch (const std::exception& e) {
      std::cout << __func__ << ": " << e.what() << std::endl;
      throw;
    }
  };
}

vector1d_F TofBetaCorr_toTr(const vector1d_F& vec_P, const vector1d_F& vec_T, const vector1d_F& vec_L, const vector1d_I& hit_num)
try {
  vector1d_F vec_T_Tp;
  vec_T_Tp.reserve(vec_P.size());
  float _c = 29.9792458f;
  for (int i = 0; i < vec_P.size(); ++i) {
    if (hit_num.at(i) == -1) {
      vec_T_Tp.push_back(-999.0f);
      continue;
    }
    
    int idx = hit_num.at(i);
    float beta = vec_L.at(idx) / ( vec_T.at(i) * _c);
    vec_T_Tp.push_back(beta);
  }
  return vec_T_Tp;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
};


//=================================================

XYZVector ExtrapolateStraightLine(const FairTrackParam *par, float z)
{
  float dz = z - par->GetZ();
  float x = par->GetX() + par->GetTx() * dz;
  float y = par->GetY() + par->GetTy() * dz;
  return {x, y, z};
}

vector<XYZVector> recPos450(const RVec<BmnGlobalTrack> tracks)
try {
  vector<XYZVector> pos;
  for (auto track:tracks) 
    pos.push_back(ExtrapolateStraightLine(track.GetParamLast(), 450));
  return pos;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector<XYZVector> tofHitPosition(const TClonesArray hits)
try {
  vector<XYZVector> pos;
  for (const auto& hitObj:hits){
    auto hit=(BmnTofHit*)hitObj;
    pos.push_back({hit->GetX(),hit->GetY(),hit->GetZ()});
  }
  return pos;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector<XYZVector> tofRes(const RVec<BmnGlobalTrack> tracks, const TClonesArray hits)
try {
  vector<XYZVector> res;
  auto testHit=(BmnTofHit*)hits.At(0);
  if (testHit)
  {
    bool tof400 = testHit->GetZ()<550 ? true : false;
    for (auto track:tracks){
      int hitIndex = tof400 ? track.GetTof1HitIndex() : track.GetTof2HitIndex();
      if (hitIndex<0 || !hits.At(hitIndex)) 
      {
        res.push_back({-999,-999,-999});
        continue;
      }
      auto hit=(BmnTofHit*)hits.At(hitIndex);
      auto par=track.GetParamLast();
      TVector3 pos;
      par->Position(pos);
      auto posAtHitZ_ = ExtrapolateStraightLine(par, hit->GetZ());
      TVector3 posAtHitZ(posAtHitZ_.x(), posAtHitZ_.y(), posAtHitZ_.z());
      TVector3 hitPos;
      hit->Position(hitPos);
      auto posDiff = hitPos - posAtHitZ; 
      res.push_back({posDiff.X(), posDiff.Y(), posDiff.Z()});
    }
  }
  return res;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_I moduleId (const vector<XYZVector> modulePos)
try {
  vector1d_I moduleIds;
  for (int i=0;i<modulePos.size();i++)
    moduleIds.push_back(i+1);
  return moduleIds;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector<XYZVector> modulePos (const char *geoFile, const char *detectorTag)
try {
  bool verbose=false;
  map <int,XYZVector> modulePosMap;
  printf("Reading %s geometry from geometry file\n", detectorTag);
  TGeoManager* geoMan = TGeoManager::Import(geoFile, "FAIRGeom");
  if( !geoMan )
    throw runtime_error(Form("ERROR: No TGeoManager in file %s", geoFile));
  TGeoNode* caveNode = geoMan->GetTopNode();
  if( !caveNode )
    throw runtime_error(Form("ERROR: No cave node in file %s", geoFile));
  TGeoNode* detectorNode = nullptr;
  TString nodeName;
  
  bool nodeFound=false;
  for (int i = 0; i < caveNode->GetNdaughters(); i++) {
    detectorNode = caveNode->GetDaughter(i);
    nodeName = detectorNode->GetName();
    nodeName.ToLower();
    if (nodeName.Contains(detectorTag))
    { 
      nodeFound=true;
      break;
    }
  }
  if( !nodeFound )
    throw runtime_error(Form("ERROR: No detector node %s in cave", detectorTag));
  detectorNode = detectorNode->GetDaughter(0);

  auto geoMatrix = detectorNode->GetMatrix();
  auto geoBox = (TGeoBBox*) detectorNode->GetVolume()->GetShape();
  TVector3 frontFaceLocal(0, 0, -geoBox->GetDZ());
  TVector3 frontFaceGlobal;
  geoMatrix->LocalToMaster(&frontFaceLocal[0], &frontFaceGlobal[0]);

  nodeName=detectorNode->GetName();
  if (nodeName.Contains("box"))
    detectorNode = detectorNode->GetDaughter(detectorNode->GetNdaughters()-1);
  printf("%s node name: %s\n", detectorTag, detectorNode->GetName());

  int nModules = detectorNode->GetNdaughters();
  for (int i = 0; i < nModules; ++i) {
    auto* daughter = detectorNode->GetDaughter(i);
    auto geoMatrix = daughter->GetMatrix();
    TVector3 translation(geoMatrix->GetTranslation());

    int modId = daughter->GetNumber();
    double x  = translation.X();
    double y  = translation.Y();
    translation.SetZ(frontFaceGlobal.Z());
    double z  = translation.Z();
    modulePosMap.insert({modId, {x,y,z}});
  }

  geoMan->GetListOfVolumes()->Delete();
  geoMan->GetListOfShapes()->Delete();
  delete geoMan;
  nModules=modulePosMap.rbegin()->first;
  vector <XYZVector> modulePosVector(nModules,{0.,0.,0.});
  for(auto &modulePos:modulePosMap)
    modulePosVector.at(modulePos.first-1)=modulePos.second;
  if (verbose)
  {
    printf("%d module positions:\n", nModules);
    for(int i=0;i<nModules;i++)
      printf("%d: (%f, %f, %f)\n", i, modulePosVector.at(i).x(), modulePosVector.at(i).y(), modulePosVector.at(i).z());
  }
  return modulePosVector;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

// FHCal
vector1d_F fhcalModE(BmnFHCalEvent event)
try {
  vector1d_F fhcalModEnergy_;
  for (int i = 0; i < 54; i++)
    fhcalModEnergy_.push_back(event.GetModule(i+1)->GetEnergy()); // *0.005: mip -> GeV
  return fhcalModEnergy_;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector2d_F fhcalSectionE(BmnFHCalEvent event)
try {
  vector2d_F fhcalSecEnergy_;
  for (Int_t iModule = 1; iModule <= event.GetTotalModules(); iModule++)
  {
    BmnFHCalModule* module = event.GetModule(iModule);
    fhcalSecEnergy_.emplace_back();
    for (Int_t iSect = 1; iSect <= module->GetNsections(); iSect++)
    {
      fhcalSecEnergy_.back().push_back(module->GetSectionEnergy(iSect)); // *0.005: mip -> GeV
    }
  }
  return fhcalSecEnergy_;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F scwallModQ(BmnScWallEvent event)
try {
  vector1d_F scwallModCharge_;
  for (int i = 0; i < 174; i++)
    scwallModCharge_.push_back(event.GetCell(i+1)->GetSignal());
  return scwallModCharge_;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F hodoStripQ(BmnHodoEvent event)
try {
  vector1d_F hodoStripCharge_;
  for (int i = 0; i < 16; i++)
    hodoStripCharge_.push_back(event.GetStrip(i+1)->GetSignal());
  return hodoStripCharge_;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F getEloss(const RVec<int> moduleId, const RVec<double> eLossDigis, const vector<XYZVector> modulePos)
try {
  int nModules=modulePos.size();
  vector1d_F eLossModules(nModules,0);
  int nDigis=eLossDigis.size();
  for(int i=0;i<nDigis;i++)
    if(moduleId.at(i) <= nModules)
      eLossModules.at(moduleId.at(i)-1)=eLossDigis.at(i);
  return eLossModules;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

RVec<bool> hasHitFhcal (RVec<CbmMCTrack> particles)
{
  RVec<bool> hasHit;
  for(auto &part:particles)
    hasHit.push_back(part.GetNPoints(kFHCAL)>0);
  return hasHit;
}

RVec<short> modNhits (RVec<short> digiModIds, RVec<short> pointModIds)
{
  RVec<short> nHits(digiModIds.size(),0);
  for (auto &pointModId:pointModIds)
    for (short i=0;i<digiModIds.size();i++)
      if(pointModId==digiModIds.at(i))
        nHits.at(i)++;
  return nHits;
}


Int_t trigNSamples(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetNSamples();
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

Float_t trigIntegral(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetIntegral(); // 
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

Float_t trigAmp(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetPeak();
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

Float_t trigTime(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetTime();
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F trigTdcTimes(const TClonesArray trigger)
try {
    auto vec = ((BmnTrigWaveDigit*)trigger.At(0))->TdcVector();
    vector1d_F result;
    result.reserve(vec.size());
    for (double val : vec) {
        result.push_back(static_cast<float>(val));
    }
    return result;
} catch (const std::exception& e) {
    std::cout << __func__ << ": " << e.what() << std::endl;
    throw;
}

vector1d_S trigValues(const RVec<BmnTrigWaveDigit> trigger)
try {
  vector<short>values;
  short* triggerValues = (trigger.at(0)).GetShortValue();
  for (int i = 0; i < 450; i++)
    values.push_back(triggerValues[i]);
  return values;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F remove_beta400_from_bad_strips(const vector1d_F fBeta, const RVec<int> fHitIndex, const RVec<int> fPlane, const RVec<int> fStrip)
try{
  vector1d_F fBetaClean_(fBeta);
  for( int i = 0; i <  fHitIndex.size(); i++){
    auto hit_idx = fHitIndex.at(i);
      if (hit_idx < 0 ) continue;
      auto plane = fPlane.at(hit_idx);
      auto strip = fStrip.at(hit_idx);
      if (auto iter_pl = tof400_strips_to_exclude.find(plane); iter_pl != tof400_strips_to_exclude.end() ){
        if ( std::find(tof400_strips_to_exclude.at(plane).begin(), tof400_strips_to_exclude.at(plane).end(), strip) != tof400_strips_to_exclude.at(plane).end())
        fBetaClean_.at(i) = -999.;
      }
  }
    return fBetaClean_;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

vector1d_F remove_beta700_from_bad_strips(const vector1d_F fBeta, const RVec<int> fHitIndex, const RVec<int> fPlane, const RVec<int> fStrip)
try{
  vector1d_F fBetaClean_(fBeta);
  for( int i = 0; i <  fHitIndex.size(); i++){
    auto hit_idx = fHitIndex.at(i);
      if (hit_idx < 0 ) continue;
      auto plane = fPlane.at(hit_idx);
      auto strip = fStrip.at(hit_idx);
      if (auto iter_pl = tof700_strips_to_exclude.find(plane); iter_pl != tof700_strips_to_exclude.end() ){
        if ( std::find(tof700_strips_to_exclude.at(plane).begin(), tof700_strips_to_exclude.at(plane).end(), strip) != tof700_strips_to_exclude.at(plane).end())
          fBetaClean_.at(i) = -999.;
      }
  }
    return fBetaClean_;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

// m2
vector1d_F trM2(const RVecF mTr, const vector1d_F fBeta)
try {
  vector1d_F trM2_;
  for (int itr=0; itr<mTr.size(); itr++) {
    auto p = mTr.at(itr);
    auto p2 = p*p;
    auto beta = fBeta.at(itr);
    auto beta2 = beta*beta;
    auto gamma2 = 1 - beta2;
    auto m2 = beta > -990. ? p2 / beta2 * gamma2 : -999.0;
    trM2_.push_back(m2);
  }
  return trM2_;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

// nSigma PID
// const auto nSigmaPID = [](TF1* f1_mean, TF1* f1_sigma){
//   return [f1_mean,f1_sigma](const RVecF vec_pq, const RVecF vec_m2){
//     vector1d_F vec_n_sigma;
//     vec_n_sigma.reserve( vec_pq.size() );
//     for( size_t i=0; i < vec_pq.size(); ++i ){
//       auto m2 = vec_m2.at(i);
//       auto pq = vec_pq.at(i);
//       auto mean = f1_mean->Eval(abs(pq));
//       auto sigma = f1_sigma->Eval(abs(pq));
//       float n_sigma = ( m2 - mean ) / sigma;
//       vec_n_sigma.push_back( (pq > 0 && m2!=-999.0) ? n_sigma : 999.0f );
//     }
//     return vec_n_sigma;     
//   };
// };

// nSigma PID
const auto nSigmaPID = [](TGraphErrors* gr_mean_plus, TGraphErrors* gr_sigma_plus, TGraphErrors *gr_mean_minus, TGraphErrors* gr_sigma_minus){
  return [gr_mean_plus, gr_sigma_plus, gr_mean_minus, gr_sigma_minus](const RVecF vec_pq, const RVecF vec_m2){
    vector1d_F vec_n_sigma;
    vec_n_sigma.reserve( vec_pq.size() );
    for( size_t i=0; i < vec_pq.size(); ++i ){
      auto m2 = vec_m2.at(i);
      auto pq = vec_pq.at(i);
      float nSigma = -999.0f;
      float mean = -999.;
      float sigma = -999.;
      if(pq<0.){
        if(gr_mean_minus!=nullptr && gr_sigma_minus!=nullptr){
          mean = gr_mean_minus->Eval(pq);
          sigma = gr_mean_minus->Eval(pq);
          nSigma = ( m2 - mean ) / sigma;
        }
      }else if(pq>0.){
        if(gr_mean_plus!=nullptr && gr_sigma_plus!=nullptr){
          mean = gr_mean_plus->Eval(pq);
          sigma = gr_sigma_plus->Eval(pq);
          nSigma = ( m2 - mean ) / sigma;
        }
      }
      vec_n_sigma.push_back( (m2!=-999.0) ? nSigma : -999.0f );
    }
    return vec_n_sigma;     
  };
};

//dEdx from Irina
//dEdx from Irina
auto CalcEnergyLoss(const std::vector<std::vector<float>>& clusters_vec)
{
    vector1d_F dedx;
    dedx.reserve(clusters_vec.size());
    for (int i = 0; i < clusters_vec.size(); i++)
    {
        const std::vector<float>& track_clusters = clusters_vec.at(i);
        std::vector<float> signal_temp_vec;
        signal_temp_vec.reserve(22);
        std::for_each(track_clusters.begin(), track_clusters.end(), [&](auto ampl)
                      { if (ampl > -100.f) signal_temp_vec.push_back(ampl); });
        std::sort(signal_temp_vec.begin(), signal_temp_vec.end());
        int nGemHits = signal_temp_vec.size();
        if (nGemHits == 0)
        {
            dedx.push_back(-999.f);
            continue;
        }
        int usedHits = arrUsedHits_50.at(nGemHits - 1);
        float totSignal = std::accumulate(signal_temp_vec.begin(), signal_temp_vec.begin() + usedHits, 0);
        if (usedHits > 0)
        {
            totSignal /= static_cast<float>(usedHits);
            dedx.push_back(totSignal);
        }
        else
            dedx.push_back(-999.f);
    }
    return dedx;
} 

const auto trEnergyLoss = [](int run_id, bool is_physical=false)
{
    return [run_id, is_physical](RVec<BmnGlobalTrack> glTracks, RVec<CbmStsTrack> stsTracks, RVec<CbmStsHit> stsHits,
                                 RVec<StripCluster> GemClustersLow, RVec<StripCluster> GemClustersUp, 
                                 RVec<StripCluster> SiliconClustersLow, RVec<StripCluster> SiliconClustersUp)
    {
        int size = glTracks.size();
        if (size == 0)
            return vector1d_F{};

        std::vector<std::vector<float>> cluster_signal_vec;

        for (int j = 0; j < glTracks.size(); j++)
        {

            auto &glTrack = glTracks.at(j);
            cluster_signal_vec.push_back(std::vector<float>(22, -999.f));

            const auto stsTrack = stsTracks.at(glTrack.GetGemTrackIndex());

            int nHits = stsTrack.GetNStsHits();

            for (int hitIdx = 0; hitIdx < nHits; hitIdx++)
            {
                const auto hit = stsHits.at(stsTrack.GetStsHitIndex(hitIdx));
                int station_num = hit.GetStationNr() - 1;

                StripCluster cluster_low;
                StripCluster cluster_up;
                if (hit.GetSystemId() == kGEM)
                {
                  cluster_low = GemClustersLow.at(hit.fDigiF % 1000000);
                  cluster_up = GemClustersUp.at(hit.fDigiB % 1000000);
                }
                else if (hit.GetSystemId() == kSILICON)
                {
                  cluster_low = SiliconClustersLow.at(hit.fDigiF % 1000000);
                  cluster_up = SiliconClustersUp.at(hit.fDigiB % 1000000);
                }

                float signal_low{0};
                float signal_up{0};
                if (is_physical)
                {
                  signal_low = g1_a_lo_runid_vec.at(station_num)->Eval(run_id) * cluster_low.TotalSignal + g1_b_lo_runid_vec.at(station_num)->Eval(run_id);
                  signal_low = g1_a_lo_plane->Eval(station_num) * signal_low + g1_b_lo_plane->Eval(station_num);
                  signal_up = g1_a_up_runid_vec.at(station_num)->Eval(run_id) * cluster_up.TotalSignal + g1_b_up_runid_vec.at(station_num)->Eval(run_id);
                  signal_up = g1_a_up_plane->Eval(station_num) * signal_up + g1_b_up_plane->Eval(station_num);
                  signal_up = a_dedx_calib * signal_up + b_dedx_calib;

                }
                else 
                {
                  signal_low = cluster_low.TotalSignal;
                  signal_up = cluster_up.TotalSignal;

                }
                cluster_signal_vec.back().at(station_num) = signal_low;
                cluster_signal_vec.back().at(station_num + 11) = signal_up;

            }
        }
            auto dedx_vec = CalcEnergyLoss(cluster_signal_vec);

            return dedx_vec;
    };
};

//pile-up by Oleg Golosov

int getValue(RVec<int> values, int index)
try {
  if(values.size()==0)return -1;
  return values.at(index);
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

int CentralHitIndexBC1S(BmnBC1hitInfo hit)
try {
  return hit.GetCentralHitIndexBC1S();
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

int BC1hitClasses(BmnBC1hitInfo hit, int centralHitIndex)
try {
  if(centralHitIndex<0)return -1;
  return hit.GetBC1hitClasses().at(centralHitIndex)==BmnEventClass::k1;
} catch (const std::exception& e) {
  std::cout << __func__ << ": " << e.what() << std::endl;
  throw;
}

auto ClosestBC1hitsDt(BmnEventClass::id classId) {
  return [classId](BmnBC1hitInfo& hit) -> vector1d_F {
    try {
      return hit.GetClosestBC1hitsDt(classId);
    } catch (const std::exception& e) {
      std::cout << __func__ << ": " << e.what() << std::endl;
      throw;
    }
  };
};

// root -l -q -b convertBmn_run8.C'("/eos/nica/bmn/exp/dst/run8/25.09.0/mpd_run_Top_7870_ev0_p6.root","/eos/nica/bmn/exp/digi/run8/25.09.0/mpd_run_Top_7870_ev0_p6.root")'

// main functions
void convertBmn_run8(std::string inReco="reco.root", std::string inDigi="digi.root", 
                     std::string inRunidDedxCalib = "./additional_files/run8_dedx_calibR_coeff.root", 
                     std::string inStsStationDedxCalib = "./additional_files/run8_dedx_calibS_coeff.root",
                     std::string fileOut = "out.tree.root",
                     std::string str_pid400_functions_file = "./additional_files/pars400_25.09.root", 
                     std::string str_pid700_functions_file = "./additional_files/pars700_25.09.root",
                     std::string VtxXYZ_corr_file = "./additional_files/run8_25.09_corr_VtxXYZ.root",
                     std::string BC1_FD_corr_file = "./additional_files/run8_25.09_corr_bc1fd.root",
                     std::string str_run_tof_calib_file = "./additional_files/tof_time_shift_calib_230726.root")
{
  
  //Вызвать 1 раз для создания словаря  
  //gInterpreter->GenerateDictionary("ROOT::RVec<ROOT::RVec<float>>", "ROOT/RVec.hxx");
  //Подключать словарь
  gSystem->Load("/nica/mpd1/demanov/convert/convert_run8_25.09/AutoDict_ROOT__RVec_ROOT__RVec_float___cxx.so");

  TStopwatch timer1;
  timer1.Start();

  TChain *chainRec=makeChain(inReco, "bmndata");
  TChain *chainDigi=makeChain(inDigi, "bmndata");
  chainRec->AddFriend(chainDigi);
  ROOT::RDataFrame d(*chainRec);

  int nEvents = chainRec->GetEntries();

  DstRunHeader* run_header = dynamic_cast<DstRunHeader*>( chainRec->GetCurrentFile()->Get("DstRunHeader") );
  if (run_header) {
    cout << "\n|||||||||||||||| RUN SUMMARY |||||||||||||||" << endl;
    cout << "||\t\t\t\t\t  ||" << endl;
    cout << "||   Period:        " << run_header->GetPeriodId() << "\t\t\t  ||" << endl;
    cout << "||   Number:        " << run_header->GetRunId() << "\t\t  ||" << endl;
    cout << "||   Start Time:    " << run_header->GetStartTime().AsString("s") << "\t  ||" << endl;
    cout << "||   End Time:      " << run_header->GetFinishTime().AsString("s") << "\t  ||" << endl;
    cout << "||   Beam:          A = " << run_header->GetBeamA() << ", Z = " << run_header->GetBeamA() << "\t  ||" << endl;
    cout << "||   Beam energy:   " << run_header->GetBeamEnergy() << " GeV\t\t  ||" << endl;
    cout << "||   Target:        A = " << run_header->GetTargetA() << ", Z = " << run_header->GetTargetZ() << "\t  ||" << endl;
    //cout << "||   Field voltage: " << setprecision(4) << run_header->GetMagneticField() << " mV\t\t  ||" << endl;
    cout << "||\t\t\t\t\t  ||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||\n" << endl;
  }
  
  auto run_id = run_header->GetRunId();
  Bool_t is_physical_run{true};

  if (std::find(physical_runs.begin(), physical_runs.end(), run_id) == physical_runs.end())
  {
      std::cout << run_id << " is NOT in a list of PHYSICAL runs\n"
                << std::endl;
      is_physical_run = false;
  }

  gRandom->SetSeed(0);
  TString geoFileName = Form("current_geo_file_%d.root", UInt_t(gRandom->Integer(UINT32_MAX)));
  Int_t res_code = UniRun::ReadGeometryFile(run_header->GetPeriodId(), run_header->GetRunId(), (char*)geoFileName.Data());
  if (res_code != 0) {
    cout << "ERROR: could not read geometry file from the database" << endl;
    exit(-3);
  }

  // get gGeoManager from ROOT file (if required)
  TFile* geoFile = new TFile(geoFileName, "READ");
  if (!geoFile->IsOpen()) {
    cout << "ERROR: could not open ROOT file with geometry: " + geoFileName << endl;
    exit(-4);
  }
  
  UniRun* pCurrentRun = UniRun::GetRun(run_header->GetPeriodId(), run_header->GetRunId());
  if (pCurrentRun == 0)
    exit(-6);
  
  Double_t* field_voltage = pCurrentRun->GetFieldVoltage();
  if (field_voltage == NULL) {
    cout << "ERROR: no field voltage was found for run " << run_header->GetPeriodId() << ":" <<  run_header->GetRunId() << endl;
    exit(-7);
  }

  Double_t map_current = 112.0;// run7 = 55.87; run8 =112.0
  Double_t fieldScale = 0.;
  if (*field_voltage < 10) {
    fieldScale = 0;
  } else
    fieldScale = (*field_voltage) / map_current;


  //dEdx calib
  auto file_calib_runid = TFile::Open(inRunidDedxCalib.c_str(), "READ");

  if (!file_calib_runid || file_calib_runid->IsZombie())
  {
      std::cerr << "Error: Could not open file " << inRunidDedxCalib << "\n";
      return;
  }
  file_calib_runid->cd();
  TGraph *g1_a_l = nullptr;
  TGraph *g1_b_l = nullptr;
  TGraph *g1_a_u = nullptr;
  TGraph *g1_b_u = nullptr;
  std::string gName_a_l, gName_b_l, gName_a_u, gName_b_u;
  for (Int_t i = 0; i < 11; i++)
  {
      gName_a_l = Form("g_a_lower_%d", i + 1);
      gName_a_u = Form("g_a_upper_%d", i + 1);
      gName_b_l = Form("g_b_lower_%d", i + 1);
      gName_b_u = Form("g_b_upper_%d", i + 1);
      file_calib_runid->GetObject(gName_a_l.c_str(), g1_a_l);
      file_calib_runid->GetObject(gName_b_l.c_str(), g1_b_l);
      file_calib_runid->GetObject(gName_a_u.c_str(), g1_a_u);
      file_calib_runid->GetObject(gName_b_u.c_str(), g1_b_u);
      g1_a_lo_runid_vec.push_back(g1_a_l);
      g1_b_lo_runid_vec.push_back(g1_b_l);
      g1_a_up_runid_vec.push_back(g1_a_u);
      g1_b_up_runid_vec.push_back(g1_b_u);
  }
  auto file_calib_plane = TFile::Open(inStsStationDedxCalib.c_str(), "READ");
  if (!file_calib_plane || file_calib_plane->IsZombie())
  {
      std::cerr << "Error: Could not open file " << inStsStationDedxCalib << "\n";
      return;
  }
  file_calib_plane->cd();
  gName_a_l = "g_a_lower";
  gName_a_u = "g_a_upper";
  gName_b_l = "g_b_lower";
  gName_b_u = "g_b_upper";
  file_calib_plane->GetObject(gName_a_l.c_str(), g1_a_lo_plane);
  file_calib_plane->GetObject(gName_b_l.c_str(), g1_b_lo_plane);
  file_calib_plane->GetObject(gName_a_u.c_str(), g1_a_up_plane);
  file_calib_plane->GetObject(gName_b_u.c_str(), g1_b_up_plane);
  file_calib_plane->GetObject("g1_coeffs_ups_to_lows", g1_a_b_uTol);
  a_dedx_calib = g1_a_b_uTol->GetPointY(0);
  b_dedx_calib = g1_a_b_uTol->GetPointY(1);
  //dEdx calib

  //FieldMap_1900_extrap_noPed
  magField = new BmnNewFieldMap("FieldMap_1900_extrap_noPed.root");
  magField->SetScale(fieldScale);
  magField->Init();

  auto scwallModPos=modulePos(geoFileName.Data(),"scwall");
  auto hodoModPos=modulePos(geoFileName.Data(),"hodo");
  auto fhcalModPos=modulePos(geoFileName.Data(),"fhcal");

  // nSigma PID 25.09
  // === ПИОНЫ (211) ===
  TGraphErrors* f1_211_m_400_plus = nullptr;
  TGraphErrors* f1_211_s_400_plus = nullptr;
  TGraphErrors* f1_211_m_400_minus = nullptr;
  TGraphErrors* f1_211_s_400_minus = nullptr;
  TGraphErrors* f1_211_m_700_plus = nullptr;
  TGraphErrors* f1_211_s_700_plus = nullptr;
  TGraphErrors* f1_211_m_700_minus = nullptr;
  TGraphErrors* f1_211_s_700_minus = nullptr;
  // === КАОНЫ (321) ===
  TGraphErrors* f1_321_m_400_plus = nullptr;
  TGraphErrors* f1_321_s_400_plus = nullptr;
  TGraphErrors* f1_321_m_400_minus = nullptr;
  TGraphErrors* f1_321_s_400_minus = nullptr;
  TGraphErrors* f1_321_m_700_plus = nullptr;
  TGraphErrors* f1_321_s_700_plus = nullptr;
  TGraphErrors* f1_321_m_700_minus = nullptr;
  TGraphErrors* f1_321_s_700_minus = nullptr;
  // === ПРОТОНЫ (2212) ===
  TGraphErrors* f1_2212_m_400 = nullptr;
  TGraphErrors* f1_2212_s_400 = nullptr;
  TGraphErrors* f1_2212_m_700 = nullptr;
  TGraphErrors* f1_2212_s_700 = nullptr;
  // === ДЕЙТРОНЫ (1000010020) ===
  TGraphErrors* f1_1000010020_m_400 = nullptr;
  TGraphErrors* f1_1000010020_s_400 = nullptr;
  TGraphErrors* f1_1000010020_m_700 = nullptr;
  TGraphErrors* f1_1000010020_s_700 = nullptr;

  auto file_pid400 = TFile::Open( str_pid400_functions_file.c_str(), "READ" );
  if (file_pid400){
    printf("reading PID function from file (TOF400)\n");
    file_pid400->cd();
    file_pid400->GetObject("211_x0", f1_211_m_400_plus);
    file_pid400->GetObject("211_sigma", f1_211_s_400_plus);
    file_pid400->GetObject("211_x0_minus", f1_211_m_400_minus);
    file_pid400->GetObject("211_sigma_minus", f1_211_s_400_minus);
    file_pid400->GetObject("321_x0", f1_321_m_400_plus);
    file_pid400->GetObject("321_sigma", f1_321_s_400_plus);
    file_pid400->GetObject("321_x0_minus", f1_321_m_400_minus);
    file_pid400->GetObject("321_sigma_minus", f1_321_s_400_minus);
    file_pid400->GetObject("2212_x0", f1_2212_m_400);
    file_pid400->GetObject("2212_sigma", f1_2212_s_400);
    file_pid400->GetObject("1000010020_sigma", f1_1000010020_s_400);
    file_pid400->GetObject("1000010020_x0", f1_1000010020_m_400);
    file_pid400->Close();
  }else{
    std::cout<<"Warning! file_pid400 not found!"<<std::endl;
  }

  auto file_pid700 = TFile::Open( str_pid700_functions_file.c_str(), "READ" );
  if(file_pid700){
    printf("reading PID function from file (TOF700)\n");
    file_pid700->cd();
    file_pid700->GetObject("211_x0", f1_211_m_700_plus);
    file_pid700->GetObject("211_sigma", f1_211_s_700_plus);
    file_pid700->GetObject("211_x0_minus", f1_211_m_700_minus);
    file_pid700->GetObject("211_sigma_minus", f1_211_s_700_minus);
    file_pid700->GetObject("321_x0", f1_321_m_700_plus);
    file_pid700->GetObject("321_sigma", f1_321_s_700_plus);
    file_pid700->GetObject("321_x0_minus", f1_321_m_700_minus);
    file_pid700->GetObject("321_sigma_minus", f1_321_s_700_minus);
    file_pid700->GetObject("2212_x0", f1_2212_m_700);
    file_pid700->GetObject("2212_sigma", f1_2212_s_700);
    file_pid700->GetObject("1000010020_sigma", f1_1000010020_s_700);
    file_pid700->GetObject("1000010020_x0", f1_1000010020_m_700);
    file_pid700->Close();
  }else{
    std::cout<<"Warning! file_pid700 not found!"<<std::endl;
  }

  // PID for 25.04 prod
  /*
  TF1* f1_211_m_400 = nullptr;
  TF1* f1_211_s_400 = nullptr;
  TF1* f1_211_m_700_proto = nullptr;
  TF1* f1_211_s_700_proto = nullptr;

  TF1* f1_2212_m_400 = nullptr;
  TF1* f1_2212_s_400 = nullptr;
  TF1* f1_2212_m_700 = nullptr;
  TF1* f1_2212_s_700 = nullptr;
  
  TF1* f1_1000010020_m_400_proto = nullptr;
  TF1* f1_1000010020_s_400 = nullptr;
  TF1* f1_1000010020_m_700_proto = nullptr;
  TF1* f1_1000010020_s_700 = nullptr;

  TF1* f1_1000010020_m_400 = new TF1("f1_1000010020_m_400", Poly3Poly3, 0., 10., 9);
  TF1* f1_211_m_700 = new TF1("f1_211_m_700", Poly3Gaus, 0., 10., 9);
  TF1* f1_211_s_700 = new TF1("f1_211_s_700", SkewGaus, 0., 10., 4);
  TF1* f1_1000010020_m_700 = new TF1("f1_1000010020_m_700", Poly3Poly3, 0., 10., 9);

  auto file_pid400 = TFile::Open( str_pid400_functions_file.c_str(), "READ" );
  if (file_pid400){
    printf("reading PID function from file (TOF400)\n");
    file_pid400->cd();
    file_pid400->GetObject("fit_211_x0", f1_211_m_400);
    file_pid400->GetObject("fit_211_sigma", f1_211_s_400);
    file_pid400->GetObject("fit_2212_x0", f1_2212_m_400);
    file_pid400->GetObject("fit_2212_sigma", f1_2212_s_400);
    file_pid400->GetObject("fit_1000010020_sigma", f1_1000010020_s_400);
    file_pid400->GetObject("fit_1000010020_x0", f1_1000010020_m_400_proto);
    double* pars400_de_x0 = new double[f1_1000010020_m_400_proto->GetNpar()];
    f1_1000010020_m_400_proto->GetParameters(pars400_de_x0);
    f1_1000010020_m_400->SetParameters(pars400_de_x0);
    delete [] pars400_de_x0;
    file_pid400->Close();
  }else{
    std::cout<<"Warning! file_pid400 not found!"<<std::endl;
  }

  auto file_pid700 = TFile::Open( str_pid700_functions_file.c_str(), "READ" );
  if(file_pid700){
    printf("reading PID function from file (TOF700)\n");
    file_pid700->cd();
    file_pid700->GetObject("fit_211_x0", f1_211_m_700_proto);
    file_pid700->GetObject("fit_211_sigma", f1_211_s_700_proto);
    double* pars700_211_x0 = new double[f1_211_m_700_proto->GetNpar()];
     double* pars700_211_s = new double[f1_211_s_700_proto->GetNpar()];
    f1_211_m_700_proto->GetParameters(pars700_211_x0);
    f1_211_s_700_proto->GetParameters(pars700_211_s);
    f1_211_m_700->SetParameters(pars700_211_x0);  
    f1_211_s_700->SetParameters(pars700_211_s);

    file_pid700->GetObject("fit_2212_x0", f1_2212_m_700);
    file_pid700->GetObject("fit_2212_sigma", f1_2212_s_700);

    file_pid700->GetObject("fit_1000010020_sigma", f1_1000010020_s_700);
    file_pid700->GetObject("fit_1000010020_x0", f1_1000010020_m_700_proto);
    double* pars700_de_x0 = new double[f1_1000010020_m_700_proto->GetNpar()];
    f1_1000010020_m_700_proto->GetParameters(pars700_de_x0);
    f1_1000010020_m_700->SetParameters(pars700_de_x0);

    delete [] pars700_211_x0;
    delete [] pars700_211_s;
    delete [] pars700_de_x0;
    delete f1_1000010020_m_400_proto;
    delete f1_1000010020_m_700_proto;
    file_pid700->Close();
  }else{
    std::cout<<"Warning! file_pid700 not found!"<<std::endl;
  }
  */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Для работы с центральностью с димом
  TGraphErrors* g1_FitVtxX = nullptr;
  TGraphErrors* g1_FitVtxY = nullptr;
  TGraphErrors* g1_FitVtxZ = nullptr;
  
  TGraphErrors* g1_m_FitBC1 = nullptr;
  TGraphErrors* g1_s_FitBC1 = nullptr;
  TGraphErrors* g1_m_FitFD = nullptr;
  TGraphErrors* g1_s_FitFD = nullptr;
  
  auto file_fit_VtxXYZ = TFile::Open( VtxXYZ_corr_file.c_str(), "READ" );
  auto file_fit_bc1fd =  TFile::Open( BC1_FD_corr_file.c_str(), "READ" );
  
  if(file_fit_VtxXYZ!=nullptr){
    file_fit_VtxXYZ->cd();
    g1_FitVtxX = file_fit_VtxXYZ->Get<TGraphErrors>("grGausNew_cct_nVtxMpd2_h2_RunId_vtx_x_mpd");
    g1_FitVtxY = file_fit_VtxXYZ->Get<TGraphErrors>("grNew_cct_nVtxMpd2_h2_RunId_vtx_y_mpd");
    g1_FitVtxZ = file_fit_VtxXYZ->Get<TGraphErrors>("grNew_cct_nVtxMpd2_h2_RunId_vtx_z_mpd");
    file_fit_VtxXYZ->Close();
  }else{
    std::cout<<"Warning! file_fit_VtxXYZ not found!"<<std::endl;
  }
  if(file_fit_bc1fd!=nullptr){
    file_fit_bc1fd->cd();
    g1_m_FitBC1 = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_bc1sInt_1");
    g1_s_FitBC1 = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_bc1sInt_2");
    g1_m_FitFD = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_fdInt_1");
    g1_s_FitFD = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_fdInt_2");
    file_fit_bc1fd->Close();
  }else{
    std::cout<<"Warning! file_fit_bc1fd not found!"<<std::endl;
  }
  ///////// Warning part /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(g1_FitVtxX==nullptr) std::cout<<"Warning! No corrections found for VtxX. These corrections will not be applied."<<std::endl;
  if(g1_FitVtxY==nullptr) std::cout<<"Warning! No corrections found for VtxY. These corrections will not be applied."<<std::endl;
  if(g1_FitVtxZ==nullptr) std::cout<<"Warning! No corrections found for VtxZ. These corrections will not be applied."<<std::endl;
  
  if(g1_m_FitBC1==nullptr) std::cout<<"Warning! No corrections found for mean BC1. These corrections will not be applied."<<std::endl;
  if(g1_s_FitBC1==nullptr) std::cout<<"Warning! No corrections found for sigma BC1. These corrections will not be applied."<<std::endl;
  if(g1_m_FitFD==nullptr) std::cout<<"Warning! No corrections found for mean FD. These corrections will not be applied."<<std::endl;
  if(g1_s_FitFD==nullptr) std::cout<<"Warning! No corrections found for sigma FD. These corrections will not be applied."<<std::endl;


  //TOF runid calib
  auto file_calib_runid_tof = TFile::Open(str_run_tof_calib_file.c_str(), "READ");
  if (!file_calib_runid_tof || file_calib_runid_tof->IsZombie())
  {
      std::cerr << "Error: Could not open file " << "\n";
      return;
  }
  file_calib_runid_tof->cd();

  TH2D* h2_400_run_calib = file_calib_runid_tof->Get<TH2D>("h_400_runid_mean_shift");
  TH2D* h2_700_run_calib = file_calib_runid_tof->Get<TH2D>("h_700_runid_mean_shift");
  TH2D* h2_400_run_strip_calib = file_calib_runid_tof->Get<TH2D>("corr_400_strip_map");
  TH2D* h2_700_run_strip_calib = file_calib_runid_tof->Get<TH2D>("corr_700_strip_map");

  h2_400_run_calib->SetDirectory(nullptr);
  h2_700_run_calib->SetDirectory(nullptr);
  h2_400_run_strip_calib->SetDirectory(nullptr);
  h2_700_run_strip_calib->SetDirectory(nullptr);

  file_calib_runid_tof->Close();
  
  if(h2_400_run_calib==nullptr) std::cout<<"Warning! No found h_400_runid_mean_shift. These corrections will not be applied."<<std::endl;
  if(h2_700_run_calib==nullptr) std::cout<<"Warning! No found h_700_runid_mean_shift. These corrections will not be applied."<<std::endl;
  if(h2_400_run_strip_calib==nullptr) std::cout<<"Warning! No found corr_400_strip_map. These corrections will not be applied."<<std::endl;
  if(h2_700_run_strip_calib==nullptr) std::cout<<"Warning! No found corr_700_strip_map. These corrections will not be applied."<<std::endl;

  //cirrections functions
  auto vtx_correction_generator = []( TGraphErrors* g1_calib ){
      return [g1_calib](float _val, UInt_t _runId){
        return (Float_t) (_val - (g1_calib!=nullptr ? g1_calib->Eval( static_cast<double>(_runId)) : 0.) );
      };
  };

  auto bc1fd_nSigma = []( TGraphErrors* g1_m_calib, TGraphErrors* g1_s_calib ){
      return [g1_m_calib,g1_s_calib](float _val, UInt_t _runId){
        auto mean = (g1_m_calib!=nullptr ? g1_m_calib->Eval( static_cast<double>(_runId)) : 0.);
        auto sigma = (g1_s_calib!=nullptr ? g1_s_calib->Eval( static_cast<double>(_runId)) : 1.);
        Float_t result = (_val - mean)/sigma;
        return result;
      };
  };

  auto RefMult_gt = [](float ptMin, float ptMax, float etaMin, float etaMax, float dcaRCut){ 
    return [ptMin, ptMax, etaMin, etaMax, dcaRCut](RVecF tr_pt, RVecF tr_eta, RVecF tr_dca_r){
      unsigned long Mult = 0;
      for( int i=0; i<tr_pt.size(); ++i ){
        if(tr_pt.at(i) < ptMin) continue;
        if(tr_pt.at(i) > ptMax) continue;
        if(tr_eta.at(i) < etaMin) continue;
        if(tr_eta.at(i) > etaMax) continue;
        if(tr_dca_r.at(i) > dcaRCut) continue;
        Mult += 1;
      }
      return Mult;
    };
  };

  auto RefMult_gt_woFakeTr = [](float ptMin, float ptMax, float etaMin, float etaMax, float dcaRCut, float FakeTrCut){ 
    return [ptMin, ptMax, etaMin, etaMax, dcaRCut, FakeTrCut](RVecF tr_pt, RVecF tr_eta, RVecF tr_dca_r, RVecF fkTrPar){
      unsigned long Mult = 0;
      for( int i=0; i<tr_pt.size(); ++i ){
        if(tr_pt.at(i) < ptMin) continue;
        if(tr_pt.at(i) > ptMax) continue;
        if(tr_eta.at(i) < etaMin) continue;
        if(tr_eta.at(i) > etaMax) continue;
        if(tr_dca_r.at(i) > dcaRCut) continue;
        if(fkTrPar.at(i) < FakeTrCut) continue;
        Mult += 1;
      }
      return Mult;
    };
  };

  auto RefMult_M = [](RVecF tr_pq){
    unsigned long Mult = 0;
    for( int i=0; i<tr_pq.size(); ++i ){
      if(tr_pq.at(i) >= 0.) continue;
      Mult += 1;
    }
    return Mult;
  };  

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  auto dd=d
    //.Range(500)
    .Define("runId",[run_id](){ return run_id; }, {} )
    .Define("evtId","DstEventHeader.fEventId")
    //trigger mask
    .Define("triggerMapBR","BmnTrigInfo.fInputsBR")
    .Define("triggerMapAR","BmnTrigInfo.fInputsAR")
    //BC1
    //.Define("bc1sNSamples",trigNSamples,{"TQDC_BC1S"})
    .Define("bc1sIntegral",trigIntegral,{"TQDC_BC1S"})
    .Define("bc1sAmplitude",trigAmp,{"TQDC_BC1S"})
    .Define("bc1sTdcValues",trigValues,{"TQDC_BC1S"})
    .Define("bc1sTdcTimes",trigTdcTimes,{"TQDC_BC1S"})
    //BC2AS
    .Define("bc2asIntegral",trigIntegral,{"TQDC_BC2AS"})
    .Define("bc2asAmplitude",trigAmp,{"TQDC_BC2AS"})
    .Define("bc2asTdcValues",trigValues,{"TQDC_BC2AS"})
    .Define("bc2asTdcTimes",trigTdcTimes,{"TQDC_BC2AS"})
    //BC2MS
    .Define("bc2msIntegral",trigIntegral,{"TQDC_BC2MS"})
    .Define("bc2msAmplitude",trigAmp,{"TQDC_BC2MS"})
    .Define("bc2msTdcValues",trigValues,{"TQDC_BC2MS"})
    .Define("bc2msTdcTimes",trigTdcTimes,{"TQDC_BC2MS"})
    //vcs
    .Define("vcsIntegral",trigIntegral,{"TQDC_VCS"})
    .Define("vcsAmplitude",trigAmp,{"TQDC_VCS"})
    .Define("vcsTdcValues",trigValues,{"TQDC_VCS"})
    .Define("vcsTdcTimes",trigTdcTimes,{"TQDC_VCS"})
    //FD
    //.Define("fdNSamples",trigNSamples,{"TQDC_FD"})
    .Define("fdIntegral",trigIntegral,{"TQDC_FD"})
    .Define("fdAmplitude",trigAmp,{"TQDC_FD"})
    .Define("fdTdcValues",trigValues,{"TQDC_FD"})
    .Define("fdTdcTimes",trigTdcTimes,{"TQDC_FD"})  
    //BD
    .Define("bdMult","BmnTrigInfo.fBDMult")
    .Define("bdModId", "BD.fMod")
    .Define("bdModAmp", "static_cast<vector1d_F>(BD.fAmp)")
    .Define("bdTrigTime", "static_cast<vector1d_F>(BD.fTime)")
    .Define("siMDMult","BmnTrigInfo.fSiMDMult")
    // pileup
    .Define("centralHitIndex", CentralHitIndexBC1S,{"BmnBC1hitInfo."})
    .Define("centralHitClass", getValue, {"BmnBC1hitInfo.fBC1hitClasses","centralHitIndex"})
    .Define("k1central",  BC1hitClasses,{"BmnBC1hitInfo.","centralHitIndex"})
    .Define("k0closest",  ClosestBC1hitsDt(BmnEventClass::k0), {"BmnBC1hitInfo."})
    .Define("kV0closest", ClosestBC1hitsDt(BmnEventClass::kV0),{"BmnBC1hitInfo."})
    .Define("k1closest",  ClosestBC1hitsDt(BmnEventClass::k1), {"BmnBC1hitInfo."})
    .Define("kV1closest", ClosestBC1hitsDt(BmnEventClass::kV1),{"BmnBC1hitInfo."})
    .Define("k0cut", "k0closest.at(0)<-200 && k0closest.at(1)>200") 
    .Define("kV0cut", "kV0closest.at(0)<-200 && kV0closest.at(1)>200") 
    .Define("k1cut", "k1closest.at(0)<-1600 && k1closest.at(1)>600") 
    .Define("kV1cut", "kV1closest.at(0)<-1800 && kV1closest.at(1)>600")
    .Define("noPileup", "if(k1central==1 && k0cut && kV0cut && k1cut && kV1cut) return 1; else if(k1central==-1) return -1; else return 0;")
    .Define("singleIon", "bc1sTdcTimes.size()==1")
    .Define("BmnBC1hitInfo_FDamp", getValue, {"BmnBC1hitInfo.fFDpeaks","centralHitIndex"})
    .Define("BmnBC1hitInfo_nBD", getValue, {"BmnBC1hitInfo.fNdigitsBD","centralHitIndex"})
    // Vertex MPD
    .Define("vtxX","(Float_t)MpdVertex.fX")
    .Define("vtxY","(Float_t)MpdVertex.fY")
    .Define("vtxZ","(Float_t)MpdVertex.fZ")
    .Define("vtxR","return sqrt(vtxX*vtxX + vtxY*vtxY);" )
    .Define("vtxNtracks","MpdVertex.fNTracks")
    .Define("vtxChi2","(Float_t)MpdVertex.fChi2")
    .Define("vtxNdf","MpdVertex.fNDF")
    .Define("vtxChi2Ndf","return (Float_t)MpdVertex.fChi2/MpdVertex.fNDF")
    // Vertex PV
    // .Define("vtxPvX","(Float_t)PrimaryVertex.fX")
    // .Define("vtxPvY","(Float_t)PrimaryVertex.fY")
    // .Define("vtxPvZ","(Float_t)PrimaryVertex.fZ")
    // .Define("vtxPvR","return sqrt(vtxX*vtxX + vtxY*vtxY);" )
    // .Define("vtxPvNtracks","PrimaryVertex.fNTracks")
    // .Define("vtxPvChi2","(Float_t)PrimaryVertex.fChi2")
    // .Define("vtxPvNdf","PrimaryVertex.fNDF")
    // .Define("vtxPvChi2Ndf","return (Float_t)PrimaryVertex.fChi2/PrimaryVertex.fNDF")
    //Total hits
    .Define("fsdMultHits", GetNHits_Convert, { "BmnSiliconHit" })
    .Define("gemMultHits", GetNHits_Convert, { "BmnGemStripHit" })
    .Define("tof400MultHits", GetNHits_Convert, { "BmnTof400Hit" })
    .Define("tof700MultHits", GetNHits_Convert, { "BmnTof700Hit" })
    .Define("sibtMultHits", GetNHits_Convert, { "BmnSiBTHit" })
    //global tracks    
    .Define("trNhits","BmnGlobalTrack.fNhits")
    .Define("trNdf","BmnGlobalTrack.fNDF")
    .Define("trChi2","BmnGlobalTrack.fChi2")
    .Define("trChi2Ndf","return trChi2/trNdf")
    .Define("trChi2vtx",ConvertToFloat_t,{"BmnGlobalTrack.fChi2InVertex"})
    .Define("trLength","BmnGlobalTrack.fLength")
    .Define("trCharge",recCharge,{"BmnGlobalTrack"})
    .Define("trDcaX",recDcaXYZR(DcaTypeConvert::X),{"BmnGlobalTrack","MpdVertex."})
    .Define("trDcaY",recDcaXYZR(DcaTypeConvert::Y),{"BmnGlobalTrack","MpdVertex."})
    .Define("trDcaZ",recDcaXYZR(DcaTypeConvert::Z),{"BmnGlobalTrack","MpdVertex."})
    .Define("trDcaR",recDcaXYZR(DcaTypeConvert::R),{"BmnGlobalTrack","MpdVertex."})
    .Define("trB_FakeTrPar",FakeTrackParam,{ "BmnGlobalTrack", "StsVector" })
    .Define("trP",GlobalTrackParamFloat(TrackParamConvert::P),{"BmnGlobalTrack"})
    .Define("trPz",GlobalTrackParamFloat(TrackParamConvert::Pz),{"BmnGlobalTrack"})
    .Define("trPq",GlobalTrackParamFloat(TrackParamConvert::Pq),{"BmnGlobalTrack"})
    .Define("trPt",GlobalTrackParamFloat(TrackParamConvert::Pt),{"BmnGlobalTrack"})
    .Define("trEta",GlobalTrackParamFloat(TrackParamConvert::Eta),{"BmnGlobalTrack"})
    .Define("trPhi",GlobalTrackParamFloat(TrackParamConvert::Phi),{"BmnGlobalTrack"})
    //dEdx Merts
    .Define("trDedx",GlobalTrackParamFloat(TrackParamConvert::Dedx),{"BmnGlobalTrack"})
    .Define("trQ",GlobalTrackParamFloat(TrackParamConvert::Q),{"BmnGlobalTrack"})
    //dEdx irina
    .Define("trEnergyLoss", trEnergyLoss(run_id, is_physical_run), {"BmnGlobalTrack", "StsVector", "StsHit", "BmnGemLowerCluster", "BmnGemUpperCluster", "BmnSiliconLowerCluster", "BmnSiliconUpperCluster"})
    //TOF
    .Define("trTof400hit","BmnGlobalTrack.fTof1Hit")//delete
    .Define("trTof700hit","BmnGlobalTrack.fTof2Hit")//delete
    //digits info        
    .Define("gemDigits","GEM.fUniqueID")
    .Define("fsdDigits","SILICON.fUniqueID")
    .Define("tof400Digits","TOF400.fUniqueID")
    .Define("tof700Digits","TOF701.fUniqueID")
    //Track
    .Define("stsTrackCovMatrix", covMatrix, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackMagField", magneticField, { "BmnGlobalTrack", "StsVector", "StsHit" })
    .Define("stsTrackParameters", stsTrackParameters, { "BmnGlobalTrack", "StsVector" })
    .Define("trParamLast", trParamLast, { "BmnGlobalTrack" })
    .Define("globalTrackParameters", trParamFirst, { "BmnGlobalTrack" })
    .Define("globalTrackCovMatrix", globalTrackCovMatrix, { "BmnGlobalTrack" })
    //sts track (FSD+GEM) с привязкой к глобал треку
    .Define("stsTrackMomentum", stsTrackMomentum, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackChi2Ndf", stsTrackChi2Ndf, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackNdf", stsTrackNdf, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackNhits", stsTrackNhits, { "BmnGlobalTrack", "StsVector" })
    //beam track
    .Define("beamHitX", beamHitXYZ(ComponentXYZ_Convert::X), { "BmnSiBTHit" })
    .Define("beamHitY", beamHitXYZ(ComponentXYZ_Convert::Y), { "BmnSiBTHit" })
    .Define("beamHitZ", beamHitXYZ(ComponentXYZ_Convert::Z), { "BmnSiBTHit" })
    .Define("beamHitStation", beamHitStation, { "BmnSiBTHit" })
    .Define("beamHitIndex",   beamHitIndex,   { "BmnSiBTHit" })
    .Define("beamTrackChi2","BmnBeamTrack.fChi2")
    .Define("beamTrackNDF", "BmnBeamTrack.fNDF")
    .Define("beamTrackB",   "BmnBeamTrack.fB")
    .Define("beamTrackParameters", BeamTrackParameters, { "BmnBeamTrack" })
    //TOF-400
    .Define("tof400Plane", TofHitPlane, {"BmnTof400Hit"})//delete
    .Define("tof400Strip", TofHitStrip, {"BmnTof400Hit"})//delete
    .Define("tof400hitPos",tofHitPosition,{"BmnTof400Hit"})//delete
    .Define("tof400hitT","static_cast<vector1d_F>(BmnTof400Hit.fTimeStamp)")//delete
    .Define("tof400hitL","static_cast<vector1d_F>(BmnTof400Hit.fLength)")//delete
    .Define("tof400hitResX","static_cast<vector1d_F>(BmnTof400Hit.fResX)")
    .Define("tof400hitResY","static_cast<vector1d_F>(BmnTof400Hit.fResY)")
    .Define("tof400hitRefIndex","BmnTof400Hit.fRefIndex")
    //TOF-700
    .Define("tof700Plane", TofHitPlane, {"BmnTof700Hit"})//delete
    .Define("tof700Strip", TofHitStrip, {"BmnTof700Hit"})//delete
    .Define("tof700hitPos",tofHitPosition,{"BmnTof700Hit"})//delete
    .Define("tof700hitT","static_cast<vector1d_F>(BmnTof700Hit.fTimeStamp)")//delete
    .Define("tof700hitL","static_cast<vector1d_F>(BmnTof700Hit.fLength)")//delete
    .Define("tof700hitResX","static_cast<vector1d_F>(BmnTof700Hit.fResX)")
    .Define("tof700hitResY","static_cast<vector1d_F>(BmnTof700Hit.fResY)")
    .Define("tof700hitRefIndex","BmnTof700Hit.fRefIndex")
    //match tr to TOF plane & strip    
    .Define("trTof400Plane", trTofHitPlane, {"trTof400hit", "tof400Plane"})//delete
    .Define("trTof400Strip", trTofHitStrip, {"trTof400hit", "tof400Strip"})//delete
    .Define("trTof700Plane", trTofHitPlane, {"trTof700hit", "tof700Plane"})//delete
    .Define("trTof700Strip", trTofHitStrip, {"trTof700hit", "tof700Strip"})//delete
    //beta, m2 and T
    .Define("trTof700hitT", trTofT, {"trP", "tof700hitT","trTof700hit"} )
		.Define("trTof400hitT", trTofT, {"trP", "tof400hitT","trTof400hit"} )
    .Define("trTof700L", trTofL, {"trP", "tof700hitL","trTof700hit"} )
		.Define("trTof400L", trTofL, {"trP", "tof400hitL","trTof400hit"} )
    .Define("trGlobalTof400StripNumber_toTr",TofStripNumberToGlTr(400),{"trP","trTof400hit","trTof400Plane","trTof400Strip"})
    .Define("trGlobalTof700StripNumber_toTr",TofStripNumberToGlTr(700),{"trP","trTof700hit","trTof700Plane","trTof700Strip"})
    .Define("trTof400hitT_corr",TofHitTCorrToGlTr(h2_400_run_calib, h2_400_run_strip_calib), {"tof400hitT","runId","trGlobalTof400StripNumber_toTr","trP","trTof400hit"})
    .Define("trTof700hitT_corr",TofHitTCorrToGlTr(h2_700_run_calib, h2_700_run_strip_calib), {"tof700hitT","runId","trGlobalTof700StripNumber_toTr","trP","trTof700hit"})
    .Define("trBetaTof400","static_cast<vector1d_F>(BmnGlobalTrack.fBeta400)")
    .Define("trBetaTof700","static_cast<vector1d_F>(BmnGlobalTrack.fBeta700)")
    .Define("trBetaTof400_corr",TofBetaCorr_toTr,{"trP", "trTof400hitT_corr","tof400hitL","trTof400hit"})
    .Define("trBetaTof700_corr",TofBetaCorr_toTr,{"trP", "trTof700hitT_corr","tof700hitL","trTof700hit"})    
    .Define("trM2Tof400",trM2,{"trP","trBetaTof400"})
    .Define("trM2Tof700",trM2,{"trP","trBetaTof700"})
    .Define("trM2Tof400_corr", trM2, {"trP", "trBetaTof400_corr"})
    .Define("trM2Tof700_corr", trM2, {"trP", "trBetaTof700_corr"})
    //.Define("trBetaTof400_clean", remove_beta400_from_bad_strips, {"trBetaTof400", "trTof400hit", "tof400Plane", "tof400Strip"})
    //.Define("trBetaTof700_clean", remove_beta700_from_bad_strips, {"trBetaTof700", "trTof700hit", "tof700Plane", "tof700Strip"})
    .Define("trNsigma_211_400",nSigmaPID(f1_211_m_400_plus,f1_211_s_400_plus,f1_211_m_400_minus,f1_211_s_400_minus),{"trPq","trM2Tof400_corr"})
    .Define("trNsigma_211_700",nSigmaPID(f1_211_m_700_plus,f1_211_s_700_plus,f1_211_m_700_minus,f1_211_s_700_minus),{"trPq","trM2Tof700_corr"})
    .Define("trNsigma_321_400",nSigmaPID(f1_321_m_400_plus,f1_321_s_400_plus,f1_321_m_400_minus,f1_321_s_400_minus),{"trPq","trM2Tof400_corr"})
    .Define("trNsigma_321_700",nSigmaPID(f1_321_m_700_plus,f1_321_s_700_plus,f1_321_m_700_minus,f1_321_s_700_minus),{"trPq","trM2Tof700_corr"})
    .Define("trNsigma_2212_400",nSigmaPID(f1_2212_m_400,f1_2212_s_400,nullptr,nullptr),{"trPq","trM2Tof400_corr"})
    .Define("trNsigma_2212_700",nSigmaPID(f1_2212_m_700,f1_2212_s_700,nullptr,nullptr),{"trPq","trM2Tof700_corr"})
    .Define("trNsigma_1000010020_400",nSigmaPID(f1_1000010020_m_400,f1_1000010020_s_400,nullptr,nullptr),{"trPq","trM2Tof400_corr"})
    .Define("trNsigma_1000010020_700",nSigmaPID(f1_1000010020_m_700,f1_1000010020_s_700,nullptr,nullptr),{"trPq","trM2Tof700_corr"})
    //scwall
    .Define("scwallModPos",[scwallModPos](){return scwallModPos;})
    .Define("scwallModId",moduleId, {"scwallModPos"})
    .Define("scwallModQ", scwallModQ, {"ScWallEvent"})
    //hodo
    .Define("hodoModPos",[hodoModPos](){return hodoModPos;})
    .Define("hodoModId",moduleId, {"hodoModPos"})
    .Define("hodoStripQ", hodoStripQ, {"HodoEvent"})
    .Define("hodoSumQ", "float Sum{}; for( auto stripQ : hodoStripQ ){ Sum+=stripQ; } return Sum; " )
    //fhcal
    .Define("fhcalModPos",[fhcalModPos](){return fhcalModPos;})
    .Define("fhcalModId", moduleId, {"fhcalModPos"})
    .Define("fhcalModE",fhcalModE,{"FHCalEvent"})
    .Define("fhcalSecE",fhcalSectionE,{"FHCalEvent"})
    .Define("fhcalSumE", "float Sum{}; for( auto modE : fhcalModE ){ Sum+=modE; } return Sum; " )
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //for Centrality
    // all ch track
    .Define("track_multiplicity", "return trPq.size();")
    .Define("track_multiplicity_gt", RefMult_gt(0.05,2.0,0.7,2.5,1),{"trPt","trEta","trDcaR"}) //0.05<pt<2 && 0.7<eta<2.7 && dca_R<1
    .Define("track_multiplicity_gt_woFakeTr", RefMult_gt_woFakeTr(0.05,2.0,0.7,2.5,1,-0.03),{"trPt","trEta","trDcaR","trB_FakeTrPar"}) //0.05<pt<2 && 0.7<eta<2.7 && dca_R<1
    .Define("track_multiplicity_M", RefMult_M,{"trPq"})
    .Define("vtxXcorr", vtx_correction_generator(g1_FitVtxX), {"vtxX","runId"})
    .Define("vtxYcorr", vtx_correction_generator(g1_FitVtxY), {"vtxY","runId"})
    .Define("vtxZcorr", vtx_correction_generator(g1_FitVtxZ), {"vtxZ","runId"})
    .Define("vtxRcorr","return sqrt(vtxXcorr*vtxXcorr + vtxYcorr*vtxYcorr);" )
    .Define("bc1sIntegral_nSigma", bc1fd_nSigma(g1_m_FitBC1,g1_s_FitBC1), {"bc1sIntegral","runId"})
    .Define("fdIntegral_nSigma", bc1fd_nSigma(g1_m_FitFD,g1_s_FitFD), {"fdIntegral","runId"})
    //Cuts
    //.Filter("vtxChi2Ndf > std::numeric_limits<float>::min()")
    //.Filter("vtxNtracks >= 2")
    //.Filter("vtxRcorr < 1.")
    //.Filter("vtxZcorr < 1.")
    //.Filter("noPileup==1")
//    .Define("fdQ","Sum(FDPoint.fCharge*FDPoint.fCharge)")
//    .Define("fdLight","Sum(FDPoint.fLightYield)")
//    .Define("fdEloss", fdEloss, {"FDPoint"})

//    .Define("bdPointEloss", mcPointEloss, {"BdPoint"})
//    .Define("bdPointModId", "BdPoint.nCopy")
//    .Define("bdPointPdg", "BdPoint.fPdgId")
//    .Define("bdPointIsPrimary", "BdPoint.fIsPrimary")
  ;
  // dd.Foreach([](uint evtId){if (evtId % 1000 == 0) cout << "\n" << evtId;}, {"evtId"}); // progress display 
  std::cout << std::endl;

  vector<string> definedNames;
  vector<string> toExclude={
    "bc1sTdcValues","bc2asTdcValues","bc2msTdcValues","vcsTdcValues","fdTdcValues",
    "tof400Plane","tof400Strip","tof400hitPos","tof400hitT","tof400hitL",
    "tof700Plane","tof700Strip","tof700hitPos","tof700hitT","tof700hitL"
    /*"scwallModPos","fhcalModPos","hodoModPos"*/
  };
  
    auto DefineColumnNames = dd.GetDefinedColumnNames();
  std::sort(DefineColumnNames.begin(), DefineColumnNames.end());
  
  //for (auto& definedName:dd.GetDefinedColumnNames())
  for (auto& definedName:DefineColumnNames)
  {
    bool exclude=false;
    for (auto &nameToExclude:toExclude)
      if (definedName==nameToExclude)
        exclude=true;
    if (!exclude){
      definedNames.push_back(definedName);
      //std::cout<<"Column name: "<< std::left << std::setw(30)<<definedName<<"Type: "<< std::left << std::setw(50) << dd.GetColumnType(definedName) << std::endl;
    }
  }
  dd.Snapshot("t", fileOut, definedNames);


/*
  // Открываем только что созданный файл для чтения
  TFile *f = TFile::Open(fileOut.c_str(), "READ");
  if (!f || f->IsZombie()) {
      std::cerr << "Ошибка открытия файла: " << fileOut << std::endl;
      return;
  }

  // Получаем указатель на TTree, которое вы сохранили
  TTree *tree = (TTree*)f->Get("t");
  if (!tree) {
      std::cerr << "Не найдено TTree с именем 't'" << std::endl;
      f->Close();
      return;
  }

  Long64_t comp_size_tot=0;
  Long64_t uncomp_size_tot=0;

  // Получаем общий размер файла
  Long64_t totalFileSize = f->GetSize(); // размер в байтах

  // Перебираем имена веток, которые вы сохранили
  for (const auto& branchName : definedNames) {
      TBranch *branch = tree->GetBranch(branchName.c_str());
      if (branch) {
          // Размер после сжатия на диске
          Long64_t zipBytes = branch->GetZipBytes();
          // "Сырой" размер данных без сжатия
          Long64_t totBytes = branch->GetTotBytes();
          
          comp_size_tot=comp_size_tot+zipBytes;
          uncomp_size_tot=uncomp_size_tot+totBytes;

          // Вычисляем процент от общего размера файла
          double percentOfFile = 0.0;
          if (totalFileSize > 0) {
              percentOfFile = (zipBytes * 100.0) / totalFileSize;
          }

          std::cout << "Branch: " << std::left << std::setw(40) << branchName
                    <<"Type: "<< std::left << std::setw(50) << dd.GetColumnType(branchName)
                    << " | Compressed: " << std::setw(10) << std::fixed << std::setprecision(2) << zipBytes / 1024.0 << " KB"
                    //<< " | Uncompressed: " << std::setw(10) << std::fixed << std::setprecision(2) << totBytes / 1024.0 << " KB"
                    << " | % of file: " << std::setw(6) << std::fixed << std::setprecision(2) << percentOfFile << "%"
                    << std::endl;
      } else {
          std::cout << "Branch " << branchName << " not found in the saved tree." << std::endl;
      }
  }

  // Дополнительно выводим общий размер файла
  std::cout << "\nTotal file size: " << std::fixed << std::setprecision(2) << totalFileSize / 1024.0 / 1024.0 << " MB" << std::endl;
  std::cout << "\nTotal file size: " << std::fixed << std::setprecision(2) << comp_size_tot / 1024.0 / 1024.0 << " MB" << std::endl;
*/
  delete h2_400_run_calib;
  delete h2_700_run_calib;
  delete h2_400_run_strip_calib;
  delete h2_700_run_strip_calib;

  std::cout<<"Convert_done"<<std::endl;
  timer1.Stop();
  timer1.Print();
}