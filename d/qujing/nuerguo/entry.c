// created by snowcat.c 4/4/1997
// room: /d/nuerguo/entry.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

�������������߸ߵĴ��š���̨�¼���һȺ�������ֵ�Ů��
�����Ų���̽��ͷ������ȥ��ѹ����ɤ����ߴߴ����С����
����ʲô��������ǰ����ڣ��ϱ��ǰ����

LONG);

  set("exits", ([
        "north"     : __DIR__"fronthall",
        "southdown" : __DIR__"towna2",
      ]));

  set("objects", ([
         __DIR__"npc/lady" : 1,
     ]));
  setup();
}

int valid_leave (object me, string dir)
{
  if ((string)me->query("id")=="woman" && dir=="north") 
    return 0;
  return 1;
}

