// =============================================================================
//
// Copyright (c) 2009-2016 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include <stdint.h>
#include <string>
#include <vector>
#include <set>
#include "Poco/DateTime.h"
#include "Poco/Nullable.h"
#include "ofx/Twitter/Types.h"
#include "ofx/Twitter/Entities.h"
#include "ofx/Twitter/Profile.h"


namespace ofx {
namespace Twitter {


class Tweet;
    

// https://dev.twitter.com/docs/platform-objects/users
class User: public BaseNamedUser
{
public:
    enum class WithheldScope
    {
        USER,
        STATUS
    };

    User();
    
    User(int64_t ID,
         const std::string& screenName,
         const std::string& name);

    virtual ~User();

    bool areContributorsEnabled() const;
    Poco::DateTime createdAt() const;
    bool hasDefaultProfile() const;
    bool hasDefaultProfileImage() const;
    std::string description() const;
    Entities entities() const;
    int favouritesCount() const;
    bool wasFollowRequestSent() const;
    int followersCount() const;
    int friendsCount() const;
    bool isGeoEnabled() const;
    bool isTranslator() const;
    std::string language() const;
    int listedCount() const;
    std::string location() const;
    Profile profile() const;
    bool isProtected() const;
    bool showsAllInlineMedia();

    /// \returns status or nullptr if not available.
    Tweet* status() const;
    int statusesCount() const;
    std::string timeZone() const;
    std::string url() const;
    int utcOffset() const;
    bool isVerified() const;
    Contries withheldInCountries() const;
    WithheldScope withheldScope() const;

private:
    bool _contributorsEnabled = false;

    Poco::DateTime _createdAt;

    bool _hasDefaultProfile = false;;

    bool _hasDefaultProfileImage = false;

    std::string _description;

    Entities _entities;

    int _favouritesCount = -1;

    bool _followRequestSent = false;

    int _followersCount =-1;

    int _friendsCount = -1;

    bool _isGeoEnabled = false;

    bool _isTranslator = false;

    std::string _language;

    int _listedCount = 0;

    std::string _location;

    Profile _profile;

    bool _isProtected = false;

    bool _showsAllInlineMedia = false;

    /// \brief Optional Twitter status.
    ///
    /// We use a std::shared_ptr to keep track to make it nullable and avoid
    /// the hassle of std::unique_ptr and copies.
    std::shared_ptr<Tweet> _status;

    int _statusesCount;

    std::string _timeZone;

    std::string _url;

    int _UTCOffset = 0;

    bool _isVerified = false;

    Contries _withheldInCountries;

    WithheldScope _withheldScope;

    friend class Deserializer;

};


} } // namespace ofx::Twitter
