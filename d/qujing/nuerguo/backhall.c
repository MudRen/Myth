// created by snowcat.c 4/4/1997
// room: /d/nuerguo/backhall.c

inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

��������������Ӽ����͵ĺ��ˡ�һ�������Ϻ���ʽ���
����������ϣ�����ׯ�����£��������̨�����ǲ������
˫������������߸ߵ���������������

LONG);

  set("exits", ([
        "north" : __DIR__"greenyard",
        "south" : __DIR__"fronthall",
      ]));

  set("objects", ([
         __DIR__"npc/princess" : 1,
         __DIR__"npc/girl" : 1,
     ]));

  setup();
}

int valid_leave (object me, string dir)
{
  object princess;
  princess = present("xiliang princess",environment(me)); 
  if (princess && dir=="north") 
  {
    return notify_fail("С����������һ���󵨣�\n");
  }
  // once get into here, reset all greenyard temps, to prevent abuse
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",0);
  return 1;
}

