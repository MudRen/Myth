// create by snowcat.c 4/20/1997
// room: /d/eastway/ciensiw.c

inherit ROOM;

void create ()
{
  set ("short", "�ȶ�����");
  set ("long", @LONG

�������ȶ����⣬������������Ĵȶ��£��ߴ������ͦ����������
������������ʯʨ�ӡ���˵���ϵĺ��һ��ǳ��Ի��ϵ����ʡ���Ժ��
�Ĵ������߸�����������һ���ٵ���
LONG);

  set("exits", ([
        "enter"     : __DIR__"ciensi",
        "north"     : __DIR__"guandao1",
      ]));
  set("outdoors", __DIR__);

  setup();
}






