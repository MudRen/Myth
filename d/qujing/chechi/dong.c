// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/dong.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ڻʹ��Ķ��ϱߣ��ɴ��ʯͷ�����������̳ɡ�����������
���г��������׿��Լ����ߴ�ĵ������·�˲�������ɫ��
�ң�������������

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi7",
        "west"         : __DIR__"zhong",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

