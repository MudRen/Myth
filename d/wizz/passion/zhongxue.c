inherit ROOM;
void create()
{
set("short", "�еȽ�������");
        set("long", @LONG
   ���������������߿�վ������ֱ�������߿��еȽ������ģ�У���͸���Ա��
ƽʱ����������������ģ�
  ǽ��һ��ֵ�ձ������look biao����������˭��ֵ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/city/kezhan",
]));
        set("objects", ([
//        __DIR__"npc/oldman": 1,
                        ]) );
        set("item_desc", ([
                 "biao": @TEXT
                    ֵ�ձ�
TEXT
        ]) );
set("valid_startroom", 1); 
set("no_time",1);  
set("no_fight", 1);  
set("no_magic", 1);  
  call_other("/obj/board/zhongxue_b", "???"); 
               setup();
}

void init()   
{
object me=this_player();   
if (userp(me) && me->query("id")!="miter" && me->query("id")!="xtaowu" && me->query("id")!="taowu" && me->query("id")!="wantfly" && !wizardp(me))
{
message_vision("\n�Բ�������������ĳ�Ա���벻Ҫ���Դ��룡\n\n",me);
me->move("/d/city/kezhan");   
}
}
