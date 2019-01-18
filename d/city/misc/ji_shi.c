//Cracked by Roath

#include <ansi.h> 
#include <room.h> 
#include <login.h> 
  
inherit ROOM; 
  
string look_sign(); 
  
void create() 
{ 
        set("short", "�� �� �� ��"); 
        set("long", @LONG 
�����ǳ����Ǽ��С����ֵĵ��̶�����һ���š�һ�شص���Ƿ�ơ� 
һ����һ���Ľ������ڸ����ֿڡ�С����˺���Ӧ�����಻������
�е� ��ڴ�������һ������(sign)�� 
LONG 
        ); 
  
        set("outdoors", "changan"); 
  
        set("item_desc", ([ 
                "sign": @TEXT 
���������������������顣 
  
join        ��ʼ������ 
  
TEXT 
        ]) ); 
  
        set("exits", ([ 
            "east" : "/d/city/beiyin1.c",
        ]) ); 
  
        set("no_fight", 1); 
        set("no_magic",1); 
  
/*
        set("objects", ([ 
               "/d/changan/npc/qianmian": 1, 
        ]) ); 
*/
  
        setup(); 
} 
  
void init() 
{ 
        add_action("do_join", "join"); 
        add_action("do_quit", "quit");
} 
  
int do_join(string arg) 
{ 
       string *name = ({ "˽��","ˮ��","ʳƷ","�¾�","�ʻ�","��ҩ","ú̿", 
                "�Ŷ�","�鱦","����","�ֻ�","ľ��","����","����","����","ũ��", 
                "��ƥ","��ƥ","����","�ӻ�", });
        object me; 
        string tempstr, namestr; 
        int i;
  
        me = this_player(); 
  
        if(me->is_busy()) return notify_fail("��������æ���أ�\n");
        if(me->query_temp("working") == 1) 
                return notify_fail("���Ѿ��ڷ��������ˣ�\n"); 
  
//yudian prevent too many dummy
        if(me->query("combat_exp") < 200000) 
                return notify_fail("������ҵ���������书���ã�\n"); 
        if(me->query("force") < 60) 
                return notify_fail("��������ˣ�\n"); 
        if(me->query("kee") < 60) 
                return notify_fail("��������ˣ�\n"); 
        if(me->query("sen") < 60) 
                return notify_fail("��������ˣ�\n"); 
        if(me->query("daoxing") < 200000)
                return notify_fail("������ҵ�������ѵ������ã�\n"); 

        namestr = name[random(sizeof(name))]; 
        tempstr = "$N��ʼ����" + namestr + "....\n"; 
        message_vision(tempstr, me); 
  
        if( namestr == "˽��" ) { 
                tempstr = "�ٱ���$N׽��������������" + namestr + 
                        "������ǿ�ͷ����������\n"; 
                message_vision(tempstr, me); 
                if( random(10) == 0 ) {         // ������� 
                        me->set("startroom", START_ROOM ); 
                        me->move( __DIR__"dalao" ); 
                        set("name", "�ٸ�"); 
                        set("id", "guanfu"); 
                        set("channel_id","���Ƹ�ʾ");
                        CHANNEL_D->do_channel(this_object(), "job", 
                                HIY+me->name() + "����" + namestr + 
                                "����������Σ��Ⱥ����ն������"NOR ); 
                } 
                else { 
                        if( random(20) == 0 ) { 
                                switch( random(9) ) { 
case 0: tempstr = "/d/city/recycle"; 
        break; 
case 1: tempstr = "/d/kaifeng/donghu"+(random(5)+1); 
        break; 
case 2: tempstr = "/d/qujing/dudi/shanlu" + ( random(10) + 1); 
        break; 
case 3: tempstr = "/d/qujing/wuzhuang/wzgmaze" + ( random(8) + 1); 
        break; 
case 4: tempstr = "/d/qujing/tianzhu/jiedao" + ( random(8) + 91); 
        break; 
case 5: tempstr = "/d/qujing/nuerguo/townc" + ( random(3) + 1); 
        break; 
case 6: tempstr = "/d/qujing/fengxian/jiedao" + ( random(14) + 1); 
        break; 
case 7: tempstr = "/d/qujing/yinwu/caopo" + ( random(5) + 1); 
        break; 
case 8: tempstr = "/d/sea/maze" + ( random(7)); 
        break; 
                                } 
                            
                                me->set("startroom", tempstr ); 
tempstr = "$N�ͳ����һ����Ʊ�Թٱ�˵����ү���кðɣ��Ҽһ��а�ʮ���������....\n" 
        + "�ٱ�����Ʊһ�����������뻳�У�̽��̽ͷ�������������ˣ��ȵ�����ô�٣�\n" 
        + "�ٱ�һ�Ž�$N�ߵ��������⣺�����㷷��" + namestr + "���»���׽������ͷ���� \n"; 
                                message_vision(tempstr, me); 
                               me->move( tempstr ); 
                        } 
                        else {                  
                                me->set("startroom", START_ROOM ); 
tempstr = "�ٱ�һ�Ű�$N���˳����������㷷��" + namestr 
        + "���»���׽������ͷ����\n"; 
                                message_vision(tempstr, me); 
                               me->move( START_ROOM ); 
                        } 
                } 
                return 1; 
        } 
  
        me->set_temp("working", 1); 
        me->set_temp("no_quit",1);
        i = 4 + random(10);
        me->start_busy(i);
        call_out( "compelete_join", i, me ); 
        return 1; 
} 
  
// modify and fix some bug
// mudring.
private void compelete_join(object me) 
{ 
        object ob; 
        int i, n; 
  
        if (!me) return; 
        me->delete_temp("working"); 
        if( present(me) ) { 
                message_vision("$N��չ���⣬����Ȼ�ۻ��ˣ��������治С��\n", me);  
                me->add("kee", -30); 
                me->add("sen", -30); 
 me->add("potential", 2+random(8));
me->add("daoxing", 4+random(8));

                n = 100 + random(100 * me->query("kar")) / 30; 
//159                  if (me->query("combat_exp")>=15000)  n=random(3);
/*
                ob = new("/obj/money/coin"); 
                ob->set_amount(n); 
                ob->move(me); 
*/
                    MONEY_D->pay_player(me, n);
                tell_object(me, "���Ǳ�ܺ͵��������ˣ�\n"); 
                tell_object(me, sprintf("��׬��%s��\n", MONEY_D->money_str(n))); 
        } 
  
        return; 
}

int do_quit(object me)
{
        me = this_player();
	if(me->query_temp("working"))
	{
	write("���⻹û���꣬�����\n");
	return 1;
         }
else return 0;
}
	
