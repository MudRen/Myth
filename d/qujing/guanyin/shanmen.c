inherit ROOM;
void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

վ��ɽ�����￴������󣬵����ȷ�����·������
�����ӹ�¥�ߣ�����������ɽ���ϵĺ���д�š�����Ժ��
�������֡���˵����ǹ�������������Ժ��
LONG);
 
 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 2,
                __DIR__"npc/guai1" : 4,
        ]));
  set("exits", ([
        "eastdown"  : __DIR__"lin7", 
        "enter" : __DIR__"langdao1",
      ])); 
  set("outdoors", __DIR__);
  setup();
}

