// rewritten by snowcat.c 4/4/1997
// Room: /nuerguo/annei.c

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��˵�ǵ��ۣ��������ڹ��ļȲ���̫���Ͼ���Ҳ���ǵ�����
�ɣ�����һ�ھ�(well)����̨�Ͽ����������֣�����̥Ȫ����
һ�ϵ������ھ�̨�߱�Ŀ������
LONG);

  set("item_desc",(["well":"һ����������Ϲ���һֻ��Ͱ��������ˮ�� \n",
        ]));
  set("exits", ([
    "out" : __DIR__"juxianan",
  ]));

  create_door("out","����","enter",DOOR_CLOSED); 

  set("objects", ([
         __DIR__"npc/niuer" : 1,
      ]));

  set("valid_startroom", 1);
  setup();
}






