//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

¥������˸��������㻨��ݣ��м���һ������������ϰ���
̴��Ƕ�����Ρ����ϰ���һЩ��С�������̣���������Ʒ����
�衢�ɹ���

LONG);

  set("exits", ([
        "down"   : __DIR__"zhenlou1",
      ]));
  set("objects", ([
        __DIR__"obj/cha" : 2,
        __DIR__"obj/guo" : 2,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

