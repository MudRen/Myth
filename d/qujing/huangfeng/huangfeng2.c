// created by angell 1/1/2001
// room: /d/qujing/huangfeng/huangfeng2.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

�ٲ�������һ��̶��̶ˮ�峺��һ����������ˮ��к��̶�У�
�����޴�ĺ��������ɽ���ˮ���������������ϡ�ԶԶ����
������������һ���ڣ�����һ������Ӱ�������С�

LONG);

  set("exits", ([
        "westdown" : __DIR__"huangfeng1",
        "northeast" : __DIR__"huangfeng3",
        "northup" : __DIR__"dongkou",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
