import Felgo 3.0
import "Organization"
import user 1.0
import communityitem 1.0
import community 1.0
import "model"
import client 1.0
import "logic"

Page {
    id:mainpage


    CommunityItem{
        id:communityitem
        property int num: 0

    }
    Community{
        id:community1
    }



    Navigation {
        navigationMode: navigationModeTabsAndDrawer
        NavigationItem {
            title: "活动"
            icon: IconType.apple

            //page with sub page navigation
            NavigationStack {
                //SecondPage { }
                CommunityActivityPage{
                    id:activitypage
                }
            }
        }

        NavigationItem {
            title: "Community"
            icon: IconType.header

            //page without navigation stack - no sub pages
            NavigationStack{

                CommunityList{
                    id:communitylist
                    //visible:true

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



    }



}
