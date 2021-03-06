// Update by aeddy@2003/04/25

#include <ansi.h>

inherit ITEM;

string *dirs = ({
"/d/city/",
"/d/westway/",
"/d/kaifeng/",
"/d/lingtai/",
"/d/moon/",
"/d/gao/",
"/d/sea/", 
"/d/jz/", 
"/d/nanhai/", 
"/d/eastway/",
"/d/ourhome/honglou/", 
"/d/xueshan/",
"/d/qujing/wuzhuang/", 
"/d/qujing/baotou/", 
"/d/qujing/baoxiang/", 
"/d/qujing/bibotan/",
"/d/qujing/biqiu/",
"/d/qujing/chechi/",
"/d/qujing/dudi/",
"/d/qujing/fengxian/",
"/d/qujing/firemount/",
"/d/qujing/heifeng/",
"/d/qujing/huangfeng/",
"/d/qujing/heishui/",
"/d/qujing/jilei/",
"/d/qujing/jindou/",
"/d/qujing/jingjiling/",
"/d/qujing/jinping/",
"/d/qujing/jisaiguo/",
"/d/qujing/kusong/",
"/d/qujing/liusha/",
"/d/qujing/maoying/",
"/d/qujing/nuerguo/",
"/d/qujing/pingding/",
"/d/qujing/pansi/",
"/d/qujing/tongtian/",
"/d/qujing/qilin/",
"/d/qujing/qinfa/",
"/d/qujing/qinglong/",
"/d/qujing/sanda/",
"/d/qujing/shuangcha/",
"/d/qujing/tianzhu/",
"/d/qujing/wudidong/",
"/d/qujing/wuji/",
"/d/qujing/xihai/",
"/d/qujing/xiaoxitian/",
"/d/qujing/yingjian/",
"/d/qujing/yinwu/",
"/d/qujing/yuhua/",
"/d/qujing/yunzhan/",
"/d/qujing/zhujie/",
"/d/qujing/zhuzi/",
"/d/penglai/"
});

void create()
{
        set_name(HIY"摇钱树树籽"NOR, ({ "seed"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一颗小小的种子。\n");
                set("unit", "颗");

        }
        setup();
        call_out("need_water", 3);
}

void init()
{
        object me = this_player();
        object env = environment();

        if( env != me ) return;

        remove_call_out("need_water");
        call_out("need_water", 10 + random(5));
        add_action("do_water", "water");
}

void need_water ()
{
        object who = environment();
        string msg;

        if( !who || !living(who) )
                return;

        if( query("dried")) return;

        if( query("id") == "seed") {
                call_out ("need_water",3);
                return;
        }

        switch( query("water") ) {
                case 0:
                         msg = name(1) + "长高了一点。\n";
                         break;
                case 1:
                         msg = name(1) + "有点蔫了，快淋一点水吧。\n";
                         break;
                case 2:
                         msg = name(1) + "开始发黄了。\n";
                         break;
                case 3:  
                         msg = name(1) + "已经失去了绿色的光泽。\n";
                         break;
                case 4:  
                         msg = name(1) + "看上去严重缺水，奄奄一息了。\n";
                         break;
                default: msg = name(1) + "干枯了。\n";
                         set("name","干" + name(1));
                         set("dried",1);
                         break;
        }
        message_vision(msg,who);
        set("water", query("water")+1);
        call_out ("need_water",random(10)+10);
        remove_call_out ("grow");
        call_out ("grow",random(5)+5);
}

int do_water (string arg)
{
        object who = this_player();
        string msg;

        if (arg != query("id"))
                return 0;

        if (query("water") >= 5) {
                message_vision ("$N的泪水一滴滴流在" + name(1) + "上。\n",who);
                return 1;
        }

        if (who->query("kee")>10)
                who->add("kee",-10);
        else {
                who->unconcious();
                return 1;
        }

        switch (random(9)) {
                case 0:
                         msg = "$N口含清水，喷在" + name(1) + "上。\n";
                         break;
                case 1:
                         msg = "$N将一点清水洒在" + name(1) + "上。\n";
                         break;
                case 2:
                         msg = "$N伸出手抓住细细的小雨，淋在" + name(1) + "上。\n";
                         break;
                case 3:
                         msg = "$N小心地捧起一点点露水，滴在" + name(1) + "上。\n";
                         break;
                case 4:
                         msg = "$N一阵心痛，泪水流在" + name(1) + "上。\n";
                         break;
                case 5:
                         msg = "$N双手捧着" + name(1) + "，伸到窗外的小雨中……\n";
                         break;
                case 6:
                         msg = "$N仔细地拿起一只小杯子，将水滴在" + name(1) + "上。\n";
                         break;
                case 7:
                         msg = "$N捧起从野外采来的晨露，洒在" + name(1) + "上。\n";
                         break;
                case 8:
                         msg = "$N用手指蘸着清水，一点点滴在" + name(1) + "上。\n";
                         break;
        }

        message_vision (msg,who);
        set("water",0);
        remove_call_out ("grow");
        call_out ("grow",random(5)+5,who);
        return 1;
}

void grow ()
{
        object who = environment();
        string msg;

        if (! living(who))
                return;

        if (query("dried")) return;

        if (query("id") == "seed") {
                if (random(3) == 0) {
                        message_vision ("树籽绽裂开，露出了一颗绿芽。\n",who);
                        set_name("绿芽", ({ "germ"}));
                        set("long","一颗正在长大的小绿芽。\n");
                        set("unit", "颗");
                } else message_vision ("树籽动了一下，胀大了一点点。\n",who);
                return;
        }

        if (query("id") == "germ") {
                if (random(6) == 0) {
                        message_vision ("绿芽终于长高了，在风中欢快地摇弋。\n",who);
                        set_name("绿苗", ({ "plant"}));
                        set("long","一棵茁壮的绿苗，上面还有些细枝。\n");
                        set("unit", "棵");
                } else message_vision ("绿芽咔嚓一声长高了一截。\n",who);
                return;
        }

        if( query("id") == "plant" )  {
                if (random(12) == 0) {
                        object flower;
                        message_vision ("绿苗终于长了一颗"HIY"金光灿灿"NOR"的大树了，枝叶上的金银在风中欢快地摇弋。\n",who);
                        flower = new (__DIR__"goldmine.c");
                        flower->set("name", who->name(1) + "的" + flower->name(1));
                        message("system",
                                WHT"┋"HIR"小道消息"NOR WHT"┋听说" + flower->name() + WHT"在"+ MISC_D->find_place(environment(who))+
                                filter_color(environment(who)->query("short")) + NOR WHT "长成了。\n"NOR, users());
                        flower->set("seed_water",log_id(who));          
                        flower->move(environment(who));
                        destruct(this_object());
                } else {
                        switch (random(3)) {
                                case 0:
                                        message_vision ("绿苗在风中跳起了舞。\n",who);
                                        break;
                                case 1:
                                        message_vision ("绿苗要长大了。\n",who);
                                        break;
                                case 2: message_vision ("绿苗微笑着。\n",who);
                                        break;
                        }
                }
        }
}

void create_seed()
{
        string dir, name;
        mixed  *files, *rooms;
        object env;

        dir = dirs[random(sizeof(dirs))];

        files = get_dir(dir,-1);

        rooms = files[random(sizeof(files))];

        while(rooms[1] == -2
        || rooms[1] <= 0 
        || (  !objectp( env = find_object(dir + rooms[0]) ) 
           && !objectp( env = load_object(dir + rooms[0]) ) ) )
                rooms = files[random(sizeof(files))];

        this_object()->move(env);

        name = MISC_D->find_place(env);
        tell_room(env, HIY"只听「啪」地一声，一粒金光闪闪的种子掉到了你的跟前。\n"NOR);
        message("channel:sys", HIW"┋天神┋摇钱树种子掉在了 [" + dir + rooms[0] +"]\n"NOR, users());
        message("system",
        WHT"┋"HIR"小道消息"NOR WHT"┋听说一颗金光闪闪的种子从"HIG"瑶池"NOR WHT"掉入人间，似乎落在" + name + WHT"。\n"NOR, users());

}