//By stey@2001/12/26 部分优化

#include <ansi.h>

inherit NPC;

/*
string *msg_d = ({
                      "救命","sos","SOS",  });
*/

void create()
{
        set_name("护士", ({"hu shi","hushi"}));
        set("title", HIY"美丽的「医护使」"NOR);
        set("gender", "女性" );
        set("age", 23);
        set("per", 40);
        set("long", HIR"一个美丽的纯洁的护士，你碰上她马上心神安宁不久进入相思甜梦。\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("str", 50);
//   　　　set("class","xian");
        set_skill("literate", 800);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("max_force", 1000);
        
        set("no_clean_up",1);
        setup();
/*
//在下面添加要监视的频道
        if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
//        if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( !clonep() ) CHANNEL_D->register_relay_channel("party");
       if( !clonep() ) CHANNEL_D->register_relay_channel("es");
       if( !clonep() ) CHANNEL_D->register_relay_channel("sldh");
       if( !clonep() ) CHANNEL_D->register_relay_channel("new");
*/
        
}

/*
void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"救护车出现，跳出几个大汉，一下就把$N抬进车子。\n$N只有无奈的躺着，哈哈，。\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=15;//这里更改自动救护时间,15=15分钟
                    
                    result = sprintf("%s在%s频道呼叫(%s)救护，进急救室医护 %d 分\n",
                    criname,channel,msg,howlong);
                    
                    criminal->set("jijiu/howlong",howlong);
                    criminal->set("jijiu/temp",result);
                    criminal->move("/d/wiz/jijiu");
                 
                    message("channel:rumor",HIM"【空穴来风】某人：据说 "HIR+criname+HIM" 在呼叫急救，被救护车送去见护士了。\n"NOR, users());
                    return;
                    }
        }
}

*/
