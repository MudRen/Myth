// 职业任务 （医师）
// created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ROOM;

string *drug1=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao"});
string *drug2=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao","/d/quest/occupation/medical/obj/yuanhancao","/d/quest/occupation/medical/obj/lingzhi","/d/quest/occupation/medical/obj/wujinggen","/d/quest/occupation/medical/obj/yinguo","/d/quest/occupation/medical/obj/heshouwu","/d/quest/occupation/medical/obj/kongqing"});
string *drug3=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao","/d/quest/occupation/medical/obj/yuanhancao","/d/quest/occupation/medical/obj/lingzhi","/d/quest/occupation/medical/obj/wujinggen","/d/quest/occupation/medical/obj/yinguo","/d/quest/occupation/medical/obj/heshouwu","/d/quest/occupation/medical/obj/kongqing","/d/quest/occupation/medical/obj/zhuguo","/d/quest/occupation/medical/obj/bingshen","/d/quest/occupation/medical/obj/tianxinshi","/d/quest/occupation/medical/obj/moguihua","/d/quest/occupation/medical/obj/huangxianlu","/d/quest/occupation/medical/obj/qxuelian"});
string *drug4=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao","/d/quest/occupation/medical/obj/yuanhancao","/d/quest/occupation/medical/obj/lingzhi","/d/quest/occupation/medical/obj/wujinggen","/d/quest/occupation/medical/obj/yinguo","/d/quest/occupation/medical/obj/heshouwu","/d/quest/occupation/medical/obj/kongqing","/d/quest/occupation/medical/obj/zhuguo","/d/quest/occupation/medical/obj/bingshen","/d/quest/occupation/medical/obj/tianxinshi","/d/quest/occupation/medical/obj/moguihua","/d/quest/occupation/medical/obj/huangxianlu","/d/quest/occupation/medical/obj/qxuelian","/d/quest/occupation/medical/obj/roufo","/d/quest/occupation/medical/obj/xdan","/d/quest/occupation/medical/obj/zizhi","/d/quest/occupation/medical/obj/moligen","/d/quest/occupation/medical/obj/changguo","/d/quest/occupation/medical/obj/xianru"});

void create()
{
        set("short", "深山老林");
        set("long", @LONG
这儿是一个荒无人烟的山林！悬崖峭壁上可以看到长着许多不知名的小
草(grass)，别看这些草看上去很普通，可是据说世间的医师们都视这些
小草为宝物，原来它们是制作能去病强身的药品的原料。
LONG
        );

        set("exits", ([   
                "north" : __DIR__"shenshan2",
        ]));
        set("objects", ([   
        ])); 
        set("no_fight",1);
        set("no_magic",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg)
{
        object me=this_player();

        if( me->is_busy() ) return notify_fail("你现在很忙！不能挖！\n");
        
        if( !arg || arg != "grass")
                return notify_fail("你要挖什么？\n");
        
        if ((me->query("sen") < 30)){  
                tell_object(me,"你的精神不能集中！\n");
                return 1;
        }
        else if ((me->query("kee") < 50 )){
                tell_object(me,"你的身体状态太差！\n");
                return 1;
        }
        
        if(!me->query("occupation") || me->query("occupation") != "医师"){
                tell_object(me,"你在干什么？\n");
                return 1;
        }
                
        if(me->query("combat_exp") < 500000){
                tell_object(me,"你的武学经验不够。\n");
                return 1;
        }

        message_vision(HIC"$N挥动锄头开始在地上挖了起来。\n"NOR,me);
        me->add("sen",-20);
        me->add("kee",-30);
        me->start_busy(6);   
        call_out("wayao",5,me);
        me->stop_busy();
        return 1;
}

int wayao(object me)
{
        object ob;

        if (random(10)<7){
                message_vision(CYN"一阵挖掘之后，$N什么也没挖到。\n"NOR,me);
                return 1;
        }
        else if ((int)me->query_skill("medical",1) > 600 ){        //神医级
                message_vision(HIG"$N在地上挖了半天，终于挖到一颗好药草。\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug4[random(22)]);
                ob->move(me);
                return 1;
        }
        else if ((int)me->query_skill("medical",1) > 400 ){        //药剂师
                message_vision(HIG"$N在地上挖了半天，终于挖到一颗不错的药草。\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug3[random(16)]);
                ob->move(me);
                return 1;
        }
        else if ((int)me->query_skill("medical",1) > 200 ){        //游医
                message_vision(HIG"$N在地上挖了半天，终于挖到一颗还算不错的药草。\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug2[random(10)]);
                ob->move(me);
                return 1;
        }       
        else{                                                      //江湖郎中
                message_vision(HIG"$N在地上挖了半天，终于挖到一颗药草。\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug1[random(4)]);
                ob->move(me);
                return 1;
        }      
        return 1;
}
