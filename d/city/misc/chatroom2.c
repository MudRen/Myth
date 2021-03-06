//Update by aeddy@2002/10/19

inherit ROOM;

void create()
{
        set("short", "大榕树上");
        set("long", @LONG

这棵大榕树真不愧为千年神木，这树上竟可盖上几层棚子，这里是第二层，据
说这里的时间也是冻结的，因此一些觉得下面太吵的人也会跑上来独自一个清
静。这里摆着几张用榕树根做的椅子，中间用几根榕树枝搭在一起，算是一个
茶几了。当你抬头往上看的时候似乎有个影在树梢之间移动，不过也许是风吹
动所造成的错觉。
LONG
        );

        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"chatroom",
        "up"  : "/d/wiz/wizroom",
        ]));

        set("no_fight",1);
        set("chat_room",1);
        set("no_magic",1);
 	 set("post_limit",1);	
        set("no_upgrade_age",1);
        set("valid_startroom","1");
        set("freeze",1);
        set("objects", ([
        ]));

		set("item_desc" , ([
	"up": "天空中漂浮着几朵白云。\n",
	]));
       
	setup();
	call_other("/cmds/usr/news", "???");
  
}

void init()
{
    if (wizardp(this_player())) return;
    add_action("do_jump","tiao");
    add_action("block_cmd", "", 1);
    add_action("do_climb", "climb");
}

int block_cmd(string args)
{
	string verb;
	object me=this_player();
	verb = query_verb();

    if (verb == "bian") return 1; // by hxl to protect qianli yan,:D
    if (verb == "xiudao") return 1;
    if (!wizardp(me) && verb == "xiudao") return 1;
    return 0;
}

int do_climb(string arg)
{
    object me;
    me=this_player();
        if( !arg || arg!="down") return notify_fail("你要往哪个方向爬？\n");

    if (me->query("gender")!="女性")
    message("vision",
        me->name() + "气喘嘘嘘的抓住树干，屁股一扭一扭地往下爬去。\n",
        environment(me), ({me}) );
   else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "象仙子般继续向下飘去，转瞬即逝。\n",
        environment(me), ({me}) );
   else message("vision",
        me->name() + "战战兢兢的抓住树干往下爬去。\n",    environment(me), ({me}) );
     me->move(__DIR__"chatroom");
     
     if (me->query("gender")!="女性")
        message("vision",
        me->name() + "气喘嘘嘘地从上面爬了下来。\n",
                environment(me), ({me}) );
 else if(me->query("age")<40&&me->query("per")>24)
        message("vision","一阵清香飞来，你定眼一看，"+
        me->name() + "已经婷婷玉立在你眼前。\n",
        environment(me), ({me}) );   
          
   else 
        message("vision", me->name() + "战战兢兢地从上面爬了下来。\n", environment(me), ({me}) );   
        
    
    return 1;
}   

int valid_leave(object me, string dir)
{
       if (dir=="up"){
	if (wizardp(me)) return 1;
	else    
	return notify_fail("爬这么高， 小心掉下来摔死!\n");
        }

        if ( dir=="down" && !wizardp(me))
        return notify_fail("这里没法直接走，看来你只能爬(climb)下去！\n");

        else return 1;
}
