/*========================== begin_copyright_notice ============================

Copyright (C) 2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#pragma once

#include "common/LLVMWarningsPush.hpp"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include "llvm/Pass.h"
#include "common/LLVMWarningsPop.hpp"

namespace IGC {
class PrintMetaDataPass : public llvm::ModulePass {
private:
  llvm::raw_ostream &Stream;
  std::vector<llvm::MDNode *> allMD;

public:
  static char ID;

  PrintMetaDataPass(llvm::raw_ostream &Stream);
  bool runOnModule(llvm::Module &M) override;

private:
  void PrintAllMD(llvm::Module *pM);
  void PrintNamedMD(llvm::Module *M);

  void CollectModuleMD(llvm::Module *M);
  void CollectFunctionMD(llvm::Function *Func);
  void CollectValueMD(llvm::Value *Val);
  void CollectInsideMD(llvm::MDNode *Node);
  void CollectInsideMD(llvm::Metadata *Node);
};
} // namespace IGC
