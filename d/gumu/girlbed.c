inherit ROOM;

void create ()
{
        set ("short", "Ů��������");
        set ("long", @LONG

�Է���������൱�ɾ��������̵��⼸��Ƥ�ޱ�֯��˯�棬����ȥ�ǳ������
LONG);

       set("exits", 
        ([ //sizeof() == 4
                  "out" : __DIR__"houting",
        ]));
        
        set("objects", 
        ([ //sizeof() == 1
  
        ]));

        set("sleep_room",1);
        set("if_bed",1);


        setup();
}
