// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xi.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ô��ʯͷ�����������̳ɣ�λ�ڳ��ٻʹ������ϱߣ�����
�ǱȽ����ֵĳ��������������г��������������������Լ�����
���ĵ��

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi6",
        "east"         : __DIR__"zhong",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

