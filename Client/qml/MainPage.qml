import Felgo 3.0
import "Organization"
Page {
    Navigation {
        NavigationItem {
            title: "Community"
            icon: IconType.header

            //page without navigation stack - no sub pages
            NavigationStack{
                Organization{
                    id:organization
                    visible:true
                }

            }
        }
        NavigationItem {
            title: "活动"
            icon: IconType

            //page with sub page navigation
            NavigationStack {
                //SecondPage { }
                CommunityActivityPage{

                }
            }
        }

        NavigationItem {
            title: "Me"
            icon: IconType.user

            //page with sub page navigation
            NavigationStack {
                //SecondPage { }
                UserPage{
                }
            }
        }
        NavigationItem {
            title: "Text"
            icon: IconType.twitter

            //page with sub page navigation
            NavigationStack {
                //SecondPage { }
                UserPageTwo{
                }
            }
        }

    }
    ActivityPage{
        id:activitypage
        visible: false
    }
    MemberList{
        id:memberlist
        visible:false
    }
}
