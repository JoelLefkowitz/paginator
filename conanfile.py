from conan import ConanFile
from conan.tools.files import copy
from conan.tools.scons import SConsDeps
from conan.tools.layout import basic_layout


class PaginatorConan(ConanFile):
    name = "paginator"
    version = "0.0.0"

    topics = ("header-only",)

    def layout(self):
        basic_layout(self, "src")

    def requirements(self):
        self.test_requires("gtest/1.12.1")

    def generate(self):
        SConsDeps(self).generate()
