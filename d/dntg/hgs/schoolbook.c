// Room: /d/4world/schoolbook.c
inherit ROOM;

void create()
{
  set ("short", "�鷿");
  set ("long", @LONG

�鷿��������൱�ɾ�����������һ�Ŵ�ĺ�ľ���������滹����
��ɫ�Ķв������ϰ���Щ�飬����Щ�ķ��ı���һ��С��ƿ�ﻹ��
��Щ������С������ǽһ��������ϰ������鼮���ϱ߿��Կ�����
����һЩ�����߶��ļ��ˡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"schoolin",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dongfangying" : 1,
  __DIR__"npc/dongfanger" : 1,
]));

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
        if ( (arg != "dongfang ying"))
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        else
write("
����ӢĿǰ��ѧ���ļ��ܣ�

  �����Ṧ (dodge)                         - ������  50/    0
  �ڹ��ķ� (force)                         - ��������  40/    0
  ����ж��֮�� (parry)                     - ������  50/    0
  �������� (sword)                         - ������  50/    0
  �˻���֮�� (unarmed)                   - ������  50/    0

\n");
                return 1;
}
