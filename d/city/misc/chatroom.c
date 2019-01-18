//modified by xigua;
//Update by aeddy@2002/10/19

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG

��˵�������ºó�����û�뵽�����ϸ����졣��ô������治��Ϊǧ����ľ��
��������Ҷ��ï����˵�����ʱ���Ƕ���ģ���˱��Ϊ����������ĵ�
����������ż������������������ӣ��м��ü�������֦����һ������һ
���輸�ˡ�����̧ͷ���Ͽ���ʱ���ƺ��и�Ӱ������֮���ƶ�������Ҳ����
�紵������ɵĴ����
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": "/d/city/center",
        "up"  : __DIR__"chatroom2",
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("no_upgrade_age",1);
        set("chat_room",1);
      set("valid_startroom","1");
        set("no_time",1);
        set("freeze",1);
   
        setup();
     
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
        if( !arg || arg!="up") return notify_fail("��Ҫ���ĸ���������\n");

    if ((string)me->query("gender")!="Ů��")
    message("vision",
        me->name() + "սս�����ؾ�ס���ɣ�ƨ��һŤһŤ�ؼ�����������\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "�����Ӱ��������Ʈȥ��ת˲���š�\n",
        environment(me), ({me}) );
     else message("vision",
        me->name() + "սս������ץס����������ȥ��\n",
        environment(me), ({me}) );
     me->move(__DIR__"chatroom2");
     me->add("kee",-10);
     if((string)me->query("gender")!="Ů��")
        message("vision",
        me->name() + "�������������������\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    
        message("vision","һ������������㶨��һ����"+
        me->name() + "�Ѿ���������������ǰ��\n",
        environment(me), ({me}) );   
  
   else 
        message("vision", me->name() + "սս�����ش���������������\n", environment(me), ({me}) );             
    return 1;
}   

int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("����æ���أ�\n");
        message("vision",
                me->name() + "��ԥ��һ�£�����������������ȥ��\n���ء���һ���죬�ƺ�����"+me->name()+"�Һ���һ��!\n",
                environment(me), ({me}) );
                me->move("/d/city/center");
        message("vision",
                me->name() + "�Һ�һ���������ϵ���������\n",
                environment(me), ({me}) );
        return 1;
}

int valid_leave(object me, string dir)
{

        if ( dir=="down" && !wizardp(me))
        return notify_fail("�̸���֪�����ĸ����һ￳���˿�����ֻ����(tiao)��ȥ��\n");
         if ( dir=="up" && !wizardp(me))
        return notify_fail("����û��ֱ���ߣ�������ֻ����(climb)��ȥ��\n");

        else return 1;
}
