//Update by aeddy@2002/10/19

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG

��ô������治��Ϊǧ����ľ�������Ͼ��ɸ��ϼ������ӣ������ǵڶ��㣬��
˵�����ʱ��Ҳ�Ƕ���ģ����һЩ��������̫������Ҳ������������һ����
����������ż������������������ӣ��м��ü�������֦����һ������һ��
�輸�ˡ�����̧ͷ���Ͽ���ʱ���ƺ��и�Ӱ������֮���ƶ�������Ҳ���Ƿ紵
������ɵĴ����
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
	"up": "�����Ư���ż�����ơ�\n",
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
        if( !arg || arg!="down") return notify_fail("��Ҫ���ĸ���������\n");

    if (me->query("gender")!="Ů��")
    message("vision",
        me->name() + "���������ץס���ɣ�ƨ��һŤһŤ��������ȥ��\n",
        environment(me), ({me}) );
   else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "�����Ӱ��������Ʈȥ��ת˲���š�\n",
        environment(me), ({me}) );
   else message("vision",
        me->name() + "սս������ץס����������ȥ��\n",    environment(me), ({me}) );
     me->move(__DIR__"chatroom");
     
     if (me->query("gender")!="Ů��")
        message("vision",
        me->name() + "��������ش���������������\n",
                environment(me), ({me}) );
 else if(me->query("age")<40&&me->query("per")>24)
        message("vision","һ������������㶨��һ����"+
        me->name() + "�Ѿ���������������ǰ��\n",
        environment(me), ({me}) );   
          
   else 
        message("vision", me->name() + "սս�����ش���������������\n", environment(me), ({me}) );   
        
    
    return 1;
}   

int valid_leave(object me, string dir)
{
       if (dir=="up"){
	if (wizardp(me)) return 1;
	else    
	return notify_fail("����ô�ߣ� С�ĵ�����ˤ��!\n");
        }

        if ( dir=="down" && !wizardp(me))
        return notify_fail("����û��ֱ���ߣ�������ֻ����(climb)��ȥ��\n");

        else return 1;
}
