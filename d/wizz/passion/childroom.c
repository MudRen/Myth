inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "幼儿园总部");
        set("long", @LONG
    这是三界神话蛇口站教育局直属机构蛇口幼儿园的办事处，
园长和辅导员们平时就是在这讨论事情的！
    墙上一张值日表你可以look biao看看现在是谁当值
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/city/kezhan",
]));
        set("objects", ([

                        ]) );
        set("item_desc", ([
                 "biao": @TEXT
                幼儿园值日表：
                花满楼        晚上
                启迪          晚上19点-22点
                火焰天使      晚上 11-7
                宇多田光      时间未定
                刀丛里的诗    时间未定
TEXT
        ]) );
set("valid_startroom", 1); 
set("no_time",1);  
set("no_fight", 1);  
set("no_magic", 1);  
               setup();
        call_other( "/obj/board/youeryuan_b", "???" );
}

void init()   
{
object me=this_player();   
if(userp(me) && me->query("id")!="blpoemde" && me->query("id")!="hjabc" && me->query("id")!="hqfa" && me->query("id")!="xsld" && me->query("id")!="ping" && me->query("id")!="yuexin" && me->query("id")!="firegirl" && me->query("id")!="qidi" && !wizardp(me) )   
{
message_vision("\n对不起，您不是幼儿园成员，请不要擅自闯入！\n\n",me); 
me->move("/d/city/kezhan");   
}



// passion add xixi
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me = this_player();
message_vision(HIY "$N一闪身没了。\n" NOR, me);
        me->move("/u/ffff/workroom");
        message_vision(HIY "只见$N湿漉漉地从天上掉了下来。\n" NOR, me);
        return 1;
}


