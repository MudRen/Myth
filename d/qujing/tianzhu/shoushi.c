// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���ε�");
  set ("long", @LONG

һ�����ɵ���ש����С�꣬����������һ�����⡱�ֵ�������
�����Ǽ���̴��ľ��������̫ʦ�Ρ�ľ���Ϸ��ż����򿪵���
�ϻ�ӣ������Ÿ������Ρ�

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao93",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_wu"   : 1,
      ]));

  setup();
}


