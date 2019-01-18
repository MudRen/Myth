// Room: /d/4world/school2.c
inherit ROOM;

void create ()
{
  set ("short", "��ݽ�����");
  set ("long", @LONG

�����Ƿ���������һ�����������������Ż�ɫ��ϸɰ����������
��������Ŭ���ز����š�����һ�䲻���۵�С�ݣ����Ű��ڡ�����
�������ʦ������Ϣ�Ĵ�����
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"schoolhall.c",
  "south" : __DIR__"school1",
  "east" : __DIR__"storage.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi" : 4,
  __DIR__"npc/dongfangcong" : 1,
]));

  set("outdoors", __DIR__"");

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
	if(!me->query("newbie/learn") )
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        if ( (arg != "dongfang cong"))
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        else
write("
������Ŀǰ��ѧ���ļ��ܣ�

  �����Ṧ (dodge)                         - ������  50/    0
  �ڹ��ķ� (force)                         - ��������  40/    0
  ����ж��֮�� (parry)                     - ������  50/    0
  �������� (stick)                         - ������  50/    0
  �˻���֮�� (unarmed)                   - ������  50/    0

\n");
                return 1;
}

