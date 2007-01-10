# Spec file for GMTL.
%define name    gmtl
%define version	0.4.12
%define release	2

Name: %{name}
Summary: The GMTL Headers
Version: %{version}
Release: %{release}
Source: %{name}-%{version}.tar.gz
URL: http://ggt.sourceforge.net/
Group: Development/C++
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot
License: LGPL
BuildPrereq: scons >= 0.96.1
BuildArch: noarch

%description
The Generic Math Template Library (GMTL) is a high-performance, extensible,
and generic math library. The design is based upon discussion with many
experts in the field of computer graphics and virtual reality, culminating the
efforts of many previous math library efforts. GMTL gives the graphics
programmer several core math types and a rich library of graphics/math
operations on those types.

%prep
rm -rf %{buildroot}
%setup -q

%build
# This needs to be fixed once we have a boost install.
scons prefix=%{_prefix}

%install
scons install prefix=%{buildroot}%{_prefix}
# Remove all stupid scons temp files
find %{buildroot}%{_prefix} -name .sconsign -exec rm {} \;
chmod 644 %{buildroot}%{_datadir}/pkgconfig/gmtl.pc
find %{buildroot}%{_prefix}/include -name \*.h -exec chmod 644 {} \;

%clean
rm -rf %{buildroot}

%pre

%post

%preun

%postun

%files
%defattr(-, root, root)
%{_bindir}/gmtl-config
%{_includedir}/gmtl
%{_datadir}/pkgconfig

%doc AUTHORS ChangeLog COPYING LICENSE.addendum README

%changelog
* Wed Jan 10 2007 Patrick Hartling <patrick@infiscape.com> 0.4.12-2
- Fixed packaging errors
