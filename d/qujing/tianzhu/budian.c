// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������������ľ���ӣ������ϰ���һЩ��ƥ������ɫ��Ⱦ
����֯�����ֲ�ϸ����н��޵ȵȡ����ӵĶ����ǰ��˸ߵĻ�
ľ��̨��

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao97",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_guo"   : 1,
      ]));

  setup();
}


