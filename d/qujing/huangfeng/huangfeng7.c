// created by angell 1/1/2001
// room: /d/qujing/huangfeng/huangfeng7.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

����Ƶ������ط��ᡣ���۵Ĳ��ɴ�أ��̲�����һ��
СϪ��·������ˮ�����ˣ���Ȼһ��������ɫ���������
�˰���Ʒ����ˡ�

LONG);

  set("exits", ([
        "northwest" : __DIR__"huangfeng8",
        "southeast" : __DIR__"huangfeng6",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
