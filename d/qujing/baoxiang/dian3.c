// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dian3.c
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������������ʣ��������ơ�ǽ�ϵ������������͸������
ȥ�����ϰ��н���֥����ޥ�����������̲ʽᣬ��λ��Ů����
���ľ�Ȼ������

LONG);

  set("exits", ([
        "west"       : __DIR__"yujie3"
      ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}


