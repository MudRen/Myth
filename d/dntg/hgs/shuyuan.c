// Room: /d/4world/shuyuan.c
inherit ROOM;

void create()
{
  set ("short", "������Ժ");
  set ("long", @LONG

���ǰ�������Ψһ����Ժ������������紾�ӣ���������ǫ�У�
�ڴ���֮�Ĳ�����ȴ����ͬ�ᡣ��Ժ������ǰ����ԭ����һλ
���������������ѧ����Ҳ�ǲ��١�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"east1",
]));
  set("objects", ([
                __DIR__"npc/xiucai": 1]) );

  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("do_skills", "skills");
}

int do_skills(string arg)
{       object ob;
        object me;
        me=this_player();
        if(!(ob = present("lan tuyu", environment(me))))
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        if ( (arg != "lan") )
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        else
write("
��ͼ��Ŀǰ��ѧ���ļ��ܣ�

  ����ʶ�� (literate)                      - ����С��  40/    0

\n");
                return 1;
}

