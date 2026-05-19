#define BMNHYPNUCLPAIR_H
using namespace ROOT;
using namespace ROOT::Math;
using namespace ROOT::RDF;
using fourVector=LorentzVector<PtEtaPhiE4D<double>>;
using VecF2D = vector<vector<float>>;
//using RVecMap = RVec<TMap<int,double>>;
//vector<float> -> RVecF
//vector Int

double Poly3Poly3(double* xx, double* pp);
double SkewGaus(double* xx, double* pp);
double Poly3Gaus(double* xx, double* pp);

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////data function/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// global track
RVecF trackPq(const RVec<BmnGlobalTrack> tracks)
try {
  RVecF momenta;
  for (auto track:tracks)
    momenta.push_back(1./track.GetParamFirst()->GetQp());
  return momenta;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVecF trackP(const RVec<BmnGlobalTrack> tracks)
try {
  RVecF momenta;
  for (auto track:tracks)
    momenta.push_back(abs(1./track.GetParamFirst()->GetQp()));
  return momenta;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<short> recCharge(const RVec<BmnGlobalTrack> tracks)
try {
  vector<short> charge;
  for (auto track:tracks) {
    int q = track.GetParamFirst()->GetQp() > 0 ? 1 : -1;
    charge.push_back(q);
  }
  return charge;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVecF trackPt(const RVec<BmnGlobalTrack> tracks)
try {
  RVecF momenta;
  for (auto track:tracks) {
    momenta.push_back(abs(track.GetPt()));
  }   
  return momenta;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVecF trackPhi(const RVec<BmnGlobalTrack> tracks)
try {
  RVecF momenta;
  for (auto track:tracks) {
    momenta.push_back(abs(track.GetPhi()));
  }   
  return momenta;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVecF trackEta(const RVec<BmnGlobalTrack> tracks)
try {
  RVecF momenta;
  for (auto track:tracks) {
    momenta.push_back(abs(track.GetEta()));
  }   
  return momenta;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

//DCA gl tr
const auto recDcaXYZR = [](std::string XYZR){
  return [XYZR](const RVec<BmnGlobalTrack> tracks, const CbmVertex vtx){
    RVecF dca;
    dca.reserve(tracks.size());
    for (auto track:tracks) {
      auto par = track.GetParamFirst();
      if(!par){
        dca.push_back(-999.0f);
        continue;
      }
      auto x = par->GetX()-vtx.GetX();
      auto y = par->GetY()-vtx.GetY();
      auto z = par->GetZ()-vtx.GetZ();
      auto r = std::sqrt( x*x + y*y );
      if(XYZR=="X")
        dca.push_back(x);
      else if (XYZR=="Y")
        dca.push_back(y);
      else if (XYZR=="Z")
        dca.push_back(z);
      else if (XYZR=="R")
        dca.push_back(r);
      else
        dca.push_back(-999.0f);
    }
    return dca;
  };
};

VecF2D covMatrix(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  VecF2D covariance_matrix;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D globalTrackCovMatrix(RVec<BmnGlobalTrack> global_tracks)
try {
  VecF2D covariance_matrix;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

float determinant3x3( const std::array<std::array<float, 3>, 3>& matrix ) try {
  auto x_0 = matrix[0][0] * ( matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]  );
  auto x_1 = matrix[0][1] * ( matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]  );
  auto x_2 = matrix[0][2] * ( matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]  );

  return x_0 - x_1 + x_2;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D magneticField(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks, RVec<CbmStsHit> sts_hits)
try {
  VecF2D magnetic_field;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D stsTrackParameters(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  VecF2D parameters;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D globalTrackParameters(RVec<BmnGlobalTrack> global_tracks)
try {
  VecF2D parameters;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D trParamFirst(RVec<BmnGlobalTrack> global_tracks)
try {
  VecF2D parameters;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D trParamLast(RVec<BmnGlobalTrack> global_tracks)
try {
  vector<vector<float>> parameters;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D BeamTrackParameters(RVec<BmnTrack> beam_tracks)
try {
  VecF2D parameters;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<float> stsTrackChi2Ndf(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  RVec<float> vec_chi2;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);

    auto chi2 = track.GetChi2();
    auto ndf = track.GetNDF();

    vec_chi2.push_back( chi2/ndf );
  }
  return vec_chi2;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<int> stsTrackNdf(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector<int> vec_ndf;
  for (auto& global_track : global_tracks) {
        auto idx = global_track.GetGemTrackIndex();
        auto track = tracks.at(idx);

    auto ndf = track.GetNDF();

    vec_ndf.push_back( ndf );
  }
  return vec_ndf;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<int> stsTrackNhits(RVec<BmnGlobalTrack> global_tracks, RVec<CbmStsTrack> tracks)
try {
  vector<int> vec_ndf;
  for (auto& global_track : global_tracks) {
    auto idx = global_track.GetGemTrackIndex();
    auto track = tracks.at(idx);

    auto ndf = track.GetNStsHits();

    vec_ndf.push_back( ndf );
  }
  return vec_ndf;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

/// BeamHit
vector<XYZVector> beamHitXYZ(const RVec<BmnSiBTHit> tracks)
try {
  vector<XYZVector> pos;
  for (auto track:tracks){
    pos.push_back({track.GetX(), track.GetY(), track.GetZ()});
  }
  return pos;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<float> beamHitStation(const RVec<BmnSiBTHit> tracks)
try {
  vector<float> _station;
  for (auto track:tracks)
    _station.push_back(track.GetStation());
  return _station;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<float> beamHitIndex(const RVec<BmnSiBTHit> tracks)
try {
  vector<float> _index;
  for (auto track:tracks)
    _index.push_back(track.GetIndex());
  return _index;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

vector<XYZVector> recPosLast(const RVec<BmnGlobalTrack> tracks)
try {
  vector<XYZVector> pos;
  for (auto track:tracks){
    auto par=track.GetParamLast();
    pos.push_back({par->GetX(), par->GetY(), par->GetZ()});
  }
  return pos;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

auto TofHitPlane(const RVec<BmnTofHit>& tofHits)
try
{
  // print.qf()
  RVec<int> hit_mod_num;
  hit_mod_num.reserve(tofHits.size());
  for( const auto& hit : tofHits )
  {
    int mod = ((hit.GetDetectorID() & 0x0000FF00) >> 8) - 1;
    hit_mod_num.push_back(mod);
  }
  return hit_mod_num;
}
catch(const std::exception &e)
{
    std::cout << __func__ << std::endl;
    throw e;
}

auto TofHitStrip(const RVec<BmnTofHit>& tofHits)
try
{
  RVec<int> hit_strip_num;
  hit_strip_num.reserve(tofHits.size());
  for( const auto& hit : tofHits )
  {
    int strip = ((hit.GetDetectorID() & 0x000000FF)) - 1;
    hit_strip_num.push_back(strip);
  }
  return hit_strip_num;
}
catch(const std::exception &e)
{
    std::cout << __func__ << std::endl;
    throw e;
}


//=========== debug functions ==================
auto trTofHitPlane(const RVec<int> fHitIndex, const vector<int>& tofHits)
try
{
  RVec<int> hit_mod_num(fHitIndex.size(), -1);
  for(int i = 0; i < fHitIndex.size(); ++i)
  {
    if (fHitIndex.at(i) < 0) continue;
    hit_mod_num.at(i) = tofHits.at(fHitIndex.at(i));
  }
  return hit_mod_num;
}
catch(const std::exception &e)
{
    std::cout << __func__ << std::endl;
    std::cout << e.what() << std::endl;
    throw e;
}

auto trTofHitStrip(const RVec<int> fHitIndex, const vector<int>& tofHits)
try
{
  RVec<int> hit_strip_num(fHitIndex.size(), -1);
  for(int i = 0; i < fHitIndex.size(); ++i)
  {
    if (fHitIndex.at(i) < 0) continue;
    hit_strip_num.at(i) = tofHits.at(fHitIndex.at(i));
  }
  return hit_strip_num;
}
catch(const std::exception &e)
{
    std::cout << __func__ << std::endl;
    std::cout << e.what() << std::endl;
    throw e;
}
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

vector<XYZVector> tofHitPosition(const TClonesArray hits)
try {
  vector<XYZVector> pos;
  for (const auto& hitObj:hits){
    auto hit=(BmnTofHit*)hitObj;
    pos.push_back({hit->GetX(),hit->GetY(),hit->GetZ()});
  }
  return pos;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<int> moduleId (const vector<XYZVector> modulePos)
try {
  RVec<int> moduleIds;
  for (int i=0;i<modulePos.size();i++)
    moduleIds.push_back(i+1);
  return moduleIds;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

// FHCal
RVec<float> fhcalModE(BmnFHCalEvent event)
try {
  RVec<float> fhcalModEnergy_;
  for (int i = 0; i < 54; i++)
    fhcalModEnergy_.push_back(event.GetModule(i+1)->GetEnergy() * 0.005); // *0.005: mip -> GeV
  return fhcalModEnergy_;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

VecF2D fhcalSectionE(BmnFHCalEvent event)
try {
  VecF2D fhcalSecEnergy_;
  for (Int_t iModule = 1; iModule <= event.GetTotalModules(); iModule++)
  {
    BmnFHCalModule* module = event.GetModule(iModule);
    fhcalSecEnergy_.emplace_back();
    for (Int_t iSect = 1; iSect <= module->GetNsections(); iSect++)
    {
      fhcalSecEnergy_.back().push_back(module->GetSectionEnergy(iSect) * 0.005); // *0.005: mip -> GeV
    }
  }
  return fhcalSecEnergy_;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<float> scwallModQ(BmnScWallEvent event)
try {
  RVec<float> scwallModCharge_;
  for (int i = 0; i < 174; i++)
    scwallModCharge_.push_back(event.GetCell(i+1)->GetSignal());
  return scwallModCharge_;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<float> hodoStripQ(BmnHodoEvent event)
try {
  RVec<float> hodoStripCharge_;
  for (int i = 0; i < 16; i++)
    hodoStripCharge_.push_back(event.GetStrip(i+1)->GetSignal());
  return hodoStripCharge_;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<float> getEloss(const RVec<int> moduleId, const RVec<double> eLossDigis, const vector<XYZVector> modulePos)
try {
  int nModules=modulePos.size();
  RVec<float> eLossModules(nModules,0);
  int nDigis=eLossDigis.size();
  for(int i=0;i<nDigis;i++)
    if(moduleId.at(i) <= nModules)
      eLossModules.at(moduleId.at(i)-1)=eLossDigis.at(i);
  return eLossModules;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
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


int trigNSamples(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetNSamples();
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

float trigIntegral(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetIntegral(); // 
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

float trigAmp(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetPeak();
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

float trigTime(const RVec<BmnTrigWaveDigit> trigger)
try {
  return (trigger.at(0)).GetTime();
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<double> trigTdcTimes(const TClonesArray trigger)
try {
  return ((BmnTrigWaveDigit*)trigger.At(0))->TdcVector();
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<short> trigValues(const RVec<BmnTrigWaveDigit> trigger)
try {
  vector<short>values;
  short* triggerValues = (trigger.at(0)).GetShortValue();
  for (int i = 0; i < 450; i++)
    values.push_back(triggerValues[i]);
  return values;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<double> remove_beta400_from_bad_strips(const RVec<double> fBeta, const RVec<int> fHitIndex, const RVec<int> fPlane, const RVec<int> fStrip)
try{
  RVec<double> fBetaClean_(fBeta);
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
} catch( const std::exception& e ){
  std::cout << e.what() << std::endl;
  std::cout << __func__ << std::endl;
  throw e;
}

RVec<double> remove_beta700_from_bad_strips(const RVec<double> fBeta, const RVec<int> fHitIndex, const RVec<int> fPlane, const RVec<int> fStrip)
try{
  RVec<double> fBetaClean_(fBeta);
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  std::cout << e.what() << std::endl;
  throw e;
}

// m2
RVec<float> trM2(const RVecF mTr, const RVec<double> fBeta)
try {
  RVec<float> trM2_;
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
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}
// nSigma PID
const auto nSigmaPID = [](TF1* f1_mean, TF1* f1_sigma){
  return [f1_mean,f1_sigma](const RVecF vec_pq, const RVecF vec_m2){
    RVecF vec_n_sigma;
    vec_n_sigma.reserve( vec_pq.size() );
    for( size_t i=0; i < vec_pq.size(); ++i ){
      auto m2 = vec_m2.at(i);
      auto pq = vec_pq.at(i);
      auto mean = f1_mean->Eval(abs(pq));
      auto sigma = f1_sigma->Eval(abs(pq));
      float n_sigma = ( m2 - mean ) / sigma;
      vec_n_sigma.push_back( (pq > 0 && m2!=-999.0) ? n_sigma : 999.0f );
    }
    return vec_n_sigma;     
  };
};

//dEdx from Irina
auto CalcEnergyLoss(const std::vector<std::vector<float>>& clusters_vec)
{
    std::vector<float> dedx;
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
            return std::vector<float>{};

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
int CentralHitIndexBC1S(BmnBC1hitInfo hit)
try {
  return hit.GetCentralHitIndexBC1S();
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

int BC1hitClasses(BmnBC1hitInfo hit, int centralHitIndex)
try {
  if(centralHitIndex<0)return -1;
  return hit.GetBC1hitClasses().at(centralHitIndex)==BmnEventClass::k1;
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

std::vector<float> ClosestBC1hitsDt_k0(BmnBC1hitInfo hit)
try {
  return hit.GetClosestBC1hitsDt(BmnEventClass::k0);
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

std::vector<float> ClosestBC1hitsDt_kV0(BmnBC1hitInfo hit)
try {
  return hit.GetClosestBC1hitsDt(BmnEventClass::kV0);
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

std::vector<float> ClosestBC1hitsDt_k1(BmnBC1hitInfo hit)
try {
  return hit.GetClosestBC1hitsDt(BmnEventClass::k1);
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}

std::vector<float> ClosestBC1hitsDt_kV1(BmnBC1hitInfo hit)
try {
  return hit.GetClosestBC1hitsDt(BmnEventClass::kV1);
} catch( const std::exception& e ){
  std::cout << __func__ << std::endl;
  throw e;
}


// root -l -q -b convertBmn_run8.C'("/eos/nica/bmn/exp/dst/run8/25.09.0/mpd_run_Top_8130_ev0_p6.root","/eos/nica/bmn/exp/dst/run8/25.09.0/mpd_run_Top_8130_ev0_p6.root")'

// main functions
void convertBmn_run8(string inReco="reco.root", string inDigi="digi.root", 
                     string inRunidDedxCalib = "run8_dedx_calibR_coeff.root", string inStsStationDedxCalib = "run8_dedx_calibS_coeff.root",
                     std::string fileOut = "out.tree.root",
                     string str_pid400_functions_file = "pars400_25.04.root", string str_pid700_functions_file = "pars700_25.04.root")
{
  
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

  //magField = new BmnNewFieldMap("field_sp41v5_ascii_Extrap.root");
  //FieldMap_1900_extrap_noPed
  magField = new BmnNewFieldMap("FieldMap_1900_extrap_noPed.root");
  magField->SetScale(fieldScale);
  magField->Init();

  auto scwallModPos=modulePos(geoFileName.Data(),"scwall");
  auto hodoModPos=modulePos(geoFileName.Data(),"hodo");
  auto fhcalModPos=modulePos(geoFileName.Data(),"fhcal");

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
  }
  




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
  
  auto file_fit_VtxXYZ = TFile::Open( "/nica/mpd1/demanov/convert/convert_run8_25.09/run8_25.09_corr_VtxXYZ_cent.root", "READ" );
  auto file_fit_bc1fd =  TFile::Open( "/nica/mpd1/demanov/convert/convert_run8_25.09/run8_25.09_corr_bc1fd_cent.root", "READ" );
  
  if(file_fit_VtxXYZ!=nullptr){
    file_fit_VtxXYZ->cd();
    g1_FitVtxX = file_fit_VtxXYZ->Get<TGraphErrors>("grGausNew_cct_nVtxMpd2_h2_RunId_vtx_x_mpd");
    g1_FitVtxY = file_fit_VtxXYZ->Get<TGraphErrors>("grNew_cct_nVtxMpd2_h2_RunId_vtx_y_mpd");
    g1_FitVtxZ = file_fit_VtxXYZ->Get<TGraphErrors>("grNew_cct_nVtxMpd2_h2_RunId_vtx_z_mpd");
    
    file_fit_bc1fd->cd();
    g1_m_FitBC1 = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_bc1sInt_1");
    g1_s_FitBC1 = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_bc1sInt_2");
    g1_m_FitFD = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_fdInt_1");
    g1_s_FitFD = file_fit_bc1fd->Get<TGraphErrors>("gr_cct_nVtxMpd2_h2_RunId_fdInt_2");
  }
  ///////// Warning part /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(g1_FitVtxX==nullptr) std::cout<<"Warning! No corrections found for VtxX. These corrections will not be applied."<<std::endl;
  if(g1_FitVtxY==nullptr) std::cout<<"Warning! No corrections found for VtxY. These corrections will not be applied."<<std::endl;
  if(g1_FitVtxZ==nullptr) std::cout<<"Warning! No corrections found for VtxZ. These corrections will not be applied."<<std::endl;
  
  if(g1_m_FitBC1==nullptr) std::cout<<"Warning! No corrections found for mean BC1. These corrections will not be applied."<<std::endl;
  if(g1_s_FitBC1==nullptr) std::cout<<"Warning! No corrections found for sigma BC1. These corrections will not be applied."<<std::endl;
  if(g1_m_FitFD==nullptr) std::cout<<"Warning! No corrections found for mean FD. These corrections will not be applied."<<std::endl;
  if(g1_s_FitFD==nullptr) std::cout<<"Warning! No corrections found for sigma FD. These corrections will not be applied."<<std::endl;

  
  //cirrections functions
  auto vtx_correction_generator = []( TGraphErrors* g1_calib ){
      return [g1_calib](double _val, UInt_t _runId){
        return _val - (g1_calib!=nullptr ? g1_calib->Eval( static_cast<double>(_runId)) : 0.);
      };
  };

  auto bc1fd_nSigma = []( TGraphErrors* g1_m_calib, TGraphErrors* g1_s_calib ){
      return [g1_m_calib,g1_s_calib](float _val, UInt_t _runId){
        auto mean = (g1_m_calib!=nullptr ? g1_m_calib->Eval( static_cast<double>(_runId)) : 0.);
        auto sigma = (g1_s_calib!=nullptr ? g1_s_calib->Eval( static_cast<double>(_runId)) : 1.);
        return (_val - mean)/sigma;
      };
  };

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





  auto dd=d
    // pileup
    .Define("centralHitIndex",CentralHitIndexBC1S,{"BmnBC1hitInfo."})
    //.Filter("centralHitIndex>=0")
    .Define("k1central",  BC1hitClasses,{"BmnBC1hitInfo.","centralHitIndex"})
    .Define("k0closest",  ClosestBC1hitsDt_k0, {"BmnBC1hitInfo."})
    .Define("kV0closest", ClosestBC1hitsDt_kV0,{"BmnBC1hitInfo."})
    .Define("k1closest",  ClosestBC1hitsDt_k1, {"BmnBC1hitInfo."})
    .Define("kV1closest", ClosestBC1hitsDt_kV1,{"BmnBC1hitInfo."})
    .Define("k0cut", "k0closest.at(0)<-200 && k0closest.at(1)>200") 
    .Define("kV0cut", "kV0closest.at(0)<-200 && kV0closest.at(1)>200") 
    .Define("k1cut", "k1closest.at(0)<-1600 && k1closest.at(1)>600") 
    .Define("kV1cut", "kV1closest.at(0)<-1800 && kV1closest.at(1)>600")
    .Define("noPileup", "if(k1central==1 && k0cut && kV0cut && k1cut && kV1cut) return 1; else if(k1central==-1) return -1; else return 0;")
    .Define("runId",[run_id](){ return run_id; }, {} )
    .Define("evtId","DstEventHeader.fEventId")
    //trigger mask
    .Define("triggerMapBR","BmnTrigInfo.fInputsBR")
    .Define("triggerMapAR","BmnTrigInfo.fInputsAR")
    //BC1
    .Define("bc1sNSamples",trigNSamples,{"TQDC_BC1S"})
    .Define("bc1sIntegral",trigIntegral,{"TQDC_BC1S"})
    .Define("bc1sAmplitude",trigAmp,{"TQDC_BC1S"})
    .Define("bc1sTrigTime",trigTime,{"TQDC_BC1S"})
    .Define("bc1sTdcValues",trigValues,{"TQDC_BC1S"})
    .Define("bc1sTdcTimes",trigTdcTimes,{"TQDC_BC1S"})
    //BC2AS
    .Define("bc2asIntegral",trigIntegral,{"TQDC_BC2AS"})
    .Define("bc2asAmplitude",trigAmp,{"TQDC_BC2AS"})
    .Define("bc2asTrigTime",trigTime,{"TQDC_BC2AS"})
    .Define("bc2asTimes",trigTdcTimes,{"TQDC_BC2AS"})
    //BC2MS
    .Define("bc2msIntegral",trigIntegral,{"TQDC_BC2MS"})
    .Define("bc2msAmplitude",trigAmp,{"TQDC_BC2MS"})
    .Define("bc2msTrigTime",trigTime,{"TQDC_BC2MS"})
    .Define("bc2msTimes",trigTdcTimes,{"TQDC_BC2MS"})
    //vcs
    .Define("vcsNSamples",trigNSamples,{"TQDC_VCS"})
    .Define("vcsIntegral",trigIntegral,{"TQDC_VCS"})
    .Define("vcsAmplitude",trigAmp,{"TQDC_VCS"})
    .Define("vcsTrigTime",trigTime,{"TQDC_VCS"})
    .Define("vcsTdcValues",trigValues,{"TQDC_VCS"})
    .Define("vcsTdcTimes",trigTdcTimes,{"TQDC_VCS"})
    //FD
    .Define("fdNSamples",trigNSamples,{"TQDC_FD"})
    .Define("fdIntegral",trigIntegral,{"TQDC_FD"})
    .Define("fdAmplitude",trigAmp,{"TQDC_FD"})
    .Define("fdTrigTime",trigTime,{"TQDC_FD"})  
    .Define("fdTdcValues",trigValues,{"TQDC_FD"})
    .Define("fdTdcTimes",trigTdcTimes,{"TQDC_FD"})  
    //BD
    .Define("bdMult","BmnTrigInfo.fBDMult")
    .Define("bdModId", "BD.fMod")
    .Define("bdModAmp", "BD.fAmp")
    .Define("bdTrigTime", "BD.fTime")
    .Define("siMDMult","BmnTrigInfo.fSiMDMult")
    // Vertex
    .Define("vtxX","MpdVertex.fX")
    .Define("vtxY","MpdVertex.fY")
    .Define("vtxZ","MpdVertex.fZ")
    .Define("vtxR","return sqrt(vtxX*vtxX + vtxY*vtxY);" )
    .Define("vtxNtracks","MpdVertex.fNTracks")
    .Define("vtxChi2","MpdVertex.fChi2")
    .Define("vtxNdf","MpdVertex.fNDF")
    .Define("vtxChi2Ndf","return MpdVertex.fChi2/MpdVertex.fNDF")
    //global tracks    
    .Define("trNhits","BmnGlobalTrack.fNhits")
    .Define("trNdf","BmnGlobalTrack.fNDF")
    .Define("trChi2","BmnGlobalTrack.fChi2")
    .Define("trChi2vtx","BmnGlobalTrack.fChi2InVertex")
    .Define("trLength","BmnGlobalTrack.fLength")
    .Define("trP",trackP,{"BmnGlobalTrack"})
    .Define("trPq",trackPq,{"BmnGlobalTrack"})
    .Define("trCharge",recCharge,{"BmnGlobalTrack"})
    .Define("trPt",trackPt,{"BmnGlobalTrack"})
    .Define("trEta",trackEta,{"BmnGlobalTrack"})
    .Define("trPhi",trackPhi,{"BmnGlobalTrack"})
    .Define("trDcaX",recDcaXYZR("X"),{"BmnGlobalTrack","MpdVertex."})
    .Define("trDcaY",recDcaXYZR("Y"),{"BmnGlobalTrack","MpdVertex."})
    .Define("trDcaZ",recDcaXYZR("Z"),{"BmnGlobalTrack","MpdVertex."})
    .Define("trDcaR",recDcaXYZR("R"),{"BmnGlobalTrack","MpdVertex."})
    //TOF
    .Define("trTof400hit","BmnGlobalTrack.fTof1Hit")
    .Define("trTof700hit","BmnGlobalTrack.fTof2Hit")
    .Define("trBetaTof400","BmnGlobalTrack.fBeta400")
    .Define("trBetaTof700","BmnGlobalTrack.fBeta700")
    //digits info        
    .Define("gemDigits","GEM.fUniqueID")
    .Define("fsdDigits","SILICON.fUniqueID")
    .Define("tof400Digits","TOF400.fUniqueID")
    .Define("tof700Digits","TOF701.fUniqueID")
    //.Define("tof400Digits","return (TOF400.fUniqueID).size()")
    //.Define("tof700Digits","return (TOF701.fUniqueID).size()") // в digi - правильная ветка 701, в dst 700
    // Далее идут vector<vector< float >> или lheujt
    .Define("stsTrackCovMatrix", covMatrix, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackMagField", magneticField, { "BmnGlobalTrack", "StsVector", "StsHit" })
    .Define("stsTrackParameters", stsTrackParameters, { "BmnGlobalTrack", "StsVector" })
    .Define("trParamLast", trParamLast, { "BmnGlobalTrack" })
    .Define("globalTrackParameters", trParamFirst, { "BmnGlobalTrack" })
    .Define("globalTrackCovMatrix", globalTrackCovMatrix, { "BmnGlobalTrack" })
    //beam track
    .Define("beamHitXYZ", beamHitXYZ, { "BmnSiBTHit" })
    .Define("beamHitStation", beamHitStation, { "BmnSiBTHit" })
    .Define("beamHitIndex",   beamHitIndex,   { "BmnSiBTHit" })
    .Define("beamTrackChi2","BmnBeamTrack.fChi2")
    .Define("beamTrackNDF", "BmnBeamTrack.fNDF")
    .Define("beamTrackB",   "BmnBeamTrack.fB")
    .Define("beamTrackParameters", BeamTrackParameters, { "BmnBeamTrack" })
    //
    .Define("stsTrackMomentum", stsTrackMomentum, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackChi2Ndf", stsTrackChi2Ndf, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackNdf", stsTrackNdf, { "BmnGlobalTrack", "StsVector" })
    .Define("stsTrackNhits", stsTrackNhits, { "BmnGlobalTrack", "StsVector" })
    //TOF-400
    .Define("tof400Plane", TofHitPlane, {"BmnTof400Hit"})
    .Define("tof400Strip", TofHitStrip, {"BmnTof400Hit"})
    .Define("tof400hitPos",tofHitPosition,{"BmnTof400Hit"})
    .Define("tof400hitT","BmnTof400Hit.fTimeStamp")
    .Define("tof400hitL","BmnTof400Hit.fLength")
    .Define("tof400hitResX","BmnTof400Hit.fResX")
    .Define("tof400hitResY","BmnTof400Hit.fResY")
    .Define("tof400hitRefIndex","BmnTof400Hit.fRefIndex")
    //.Define("tof400hitResCalc",tofRes,{"BmnGlobalTrack","BmnTof400Hit"})// можно убрать
    //TOF-700
    .Define("tof700Plane", TofHitPlane, {"BmnTof700Hit"})
    .Define("tof700Strip", TofHitStrip, {"BmnTof700Hit"})
    .Define("tof700hitPos",tofHitPosition,{"BmnTof700Hit"})
    .Define("tof700hitT","BmnTof700Hit.fTimeStamp")
    .Define("tof700hitL","BmnTof700Hit.fLength")
    .Define("tof700hitResX","BmnTof700Hit.fResX")
    .Define("tof700hitResY","BmnTof700Hit.fResY")
    .Define("tof700hitRefIndex","BmnTof700Hit.fRefIndex")
    //.Define("tof700hitResCalc",tofRes,{"BmnGlobalTrack","BmnTof700Hit"})// можно убрать
    //beta and m2
    .Define("trM2Tof400",trM2,{"trP","trBetaTof400"})
    .Define("trM2Tof700",trM2,{"trP","trBetaTof700"})
    .Define("trBetaTof400_clean", remove_beta400_from_bad_strips, {"trBetaTof400", "trTof400hit", "tof400Plane", "tof400Strip"})
    .Define("trBetaTof700_clean", remove_beta700_from_bad_strips, {"trBetaTof700", "trTof700hit", "tof700Plane", "tof700Strip"})
    .Define("trM2Tof400_clean", trM2, {"trP", "trBetaTof400_clean"})
    .Define("trM2Tof700_clean", trM2, {"trP", "trBetaTof700_clean"})
    .Define("trNsigma_211_400",nSigmaPID(f1_211_m_400,f1_211_s_400),{"trPq","trM2Tof400_clean"})
    .Define("trNsigma_211_700",nSigmaPID(f1_211_m_700,f1_211_s_700),{"trPq","trM2Tof700_clean"})
    .Define("trNsigma_211_700_proto",nSigmaPID(f1_211_m_700_proto,f1_211_s_700_proto),{"trPq","trM2Tof700_clean"})
    .Define("trNsigma_2212_400",nSigmaPID(f1_2212_m_400,f1_2212_s_400),{"trPq","trM2Tof400_clean"})
    .Define("trNsigma_2212_700",nSigmaPID(f1_2212_m_700,f1_2212_s_700),{"trPq","trM2Tof700_clean"})
    .Define("trNsigma_1000010020_400",nSigmaPID(f1_1000010020_m_400,f1_1000010020_s_400),{"trPq","trM2Tof400_clean"})
    .Define("trNsigma_1000010020_700",nSigmaPID(f1_1000010020_m_700,f1_1000010020_s_700),{"trPq","trM2Tof700_clean"})
    //dEdx
    .Define("trEnergyLoss", trEnergyLoss(run_id, is_physical_run), {"BmnGlobalTrack", "StsVector", "StsHit", "BmnGemLowerCluster", "BmnGemUpperCluster", "BmnSiliconLowerCluster", "BmnSiliconUpperCluster"})
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
    //for Centrality with Dim
    .Define( "vtxXcorr", vtx_correction_generator(g1_FitVtxX), {"vtxX","runId"})
    .Define( "vtxYcorr", vtx_correction_generator(g1_FitVtxY), {"vtxY","runId"})
    .Define( "vtxZcorr", vtx_correction_generator(g1_FitVtxZ), {"vtxZ","runId"})
    .Define( "vtxRcorr","return sqrt(vtxXcorr*vtxXcorr + vtxYcorr*vtxYcorr);" )
    .Define( "bc1sIntegral_nSigma", bc1fd_nSigma(g1_m_FitBC1,g1_s_FitBC1), {"bc1sIntegral","runId"})
    .Define( "fdIntegral_nSigma", bc1fd_nSigma(g1_m_FitFD,g1_s_FitFD), {"fdIntegral","runId"})
    //Cuts
    .Filter("vtxChi2Ndf > std::numeric_limits<float>::min()")
    .Filter("vtxNtracks >= 2")
    .Filter("vtxRcorr < 1.")
    .Filter("vtxZcorr < 1.")
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
  vector<string> toExclude={/*"scwallModPos","fhcalModPos","hodoModPos"*/};
  for (auto& definedName:dd.GetDefinedColumnNames())
  {
    bool exclude=false;
    for (auto &nameToExclude:toExclude)
      if (definedName==nameToExclude)
        exclude=true;
    if (!exclude)
      definedNames.push_back(definedName);
  }
  dd.Snapshot("t", fileOut, definedNames);

  std::cout<<"Convert_done"<<std::endl;
  timer1.Stop();
  timer1.Print();
}

double Poly3Poly3(double* xx, double* pp)
{
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

double SkewGaus(double* xx, double* pp)
{
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

double Poly3Gaus(double* xx, double* pp)
{
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