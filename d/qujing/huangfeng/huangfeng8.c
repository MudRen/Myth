// created by angell 1/1/2001
// room: /d/qujing/huangfeng/huangfeng8.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

����Ƶ������ط��ᡣ���۵Ĳ��ɴ�أ��̲�����һ��
СϪ��·������ˮ�����ˣ���Ȼһ��������ɫ��������ͨ
�������ȡ��·��

LONG);

  set("exits", ([
        "west" : "/d/qujing/baigudong/shanshipo",
        "southeast" : __DIR__"huangfeng7",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
