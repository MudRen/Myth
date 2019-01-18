// Created by kuku@sjsh 2003.2
// ְҵ���� ���󹤣���������������

#include <ansi.h>
inherit ITEM;  

string *kuang1=({"/d/quest/occupation/wakuang/obj/tong-kuang","/d/quest/occupation/wakuang/obj/tie-kuang"});
string *kuang2=({"/d/quest/occupation/wakuang/obj/tong-kuang","/d/quest/occupation/wakuang/obj/tie-kuang","/d/quest/occupation/wakuang/obj/zitong-kuang"});
string *kuang3=({"/d/quest/occupation/wakuang/obj/tong-kuang","/d/quest/occupation/wakuang/obj/tie-kuang","/d/quest/occupation/wakuang/obj/zitong-kuang","/d/quest/occupation/wakuang/obj/chitie-kuang"});
string *kuang4=({"/d/quest/occupation/wakuang/obj/tong-kuang","/d/quest/occupation/wakuang/obj/tie-kuang","/d/quest/occupation/wakuang/obj/zitong-kuang","/d/quest/occupation/wakuang/obj/chitie-kuang","/d/quest/occupation/wakuang/obj/nietie-kuang"});
string *kuang5=({"/d/quest/occupation/wakuang/obj/tong-kuang","/d/quest/occupation/wakuang/obj/tie-kuang","/d/quest/occupation/wakuang/obj/zitong-kuang","/d/quest/occupation/wakuang/obj/chitie-kuang","/d/quest/occupation/wakuang/obj/nietie-kuang","/d/quest/occupation/wakuang/obj/yin-kuang"});
string *kuang6=({"/d/quest/occupation/wakuang/obj/tong-kuang","/d/quest/occupation/wakuang/obj/tie-kuang","/d/quest/occupation/wakuang/obj/zitong-kuang","/d/quest/occupation/wakuang/obj/chitie-kuang","/d/quest/occupation/wakuang/obj/nietie-kuang","/d/quest/occupation/wakuang/obj/yin-kuang","/d/quest/occupation/wakuang/obj/jin-kuang"});

void init()
{
        add_action("do_wakuang", "wakuang");
}

void create() 
{
        set_name("����",({"kuang mai", "mai"}));
        set_weight(500000000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
                set("no_put",1);
                set("no_get",1);
                set("no_give",1);
                set("long", "����һ���ܺõĿ�����������ã�wakuang�����������������Ρ�\n");
        }
        setup();
}

int do_wakuang()
{
        object me=this_player();

        if( me->is_busy() ) return notify_fail("�����ں�æ�������ڣ�\n");
        if ((me->query("sen") < 30)){  
                tell_object(me,"��ľ����ܼ��У��������ڿ�ʯ��\n");
                return 1;
        }
        else if ((me->query("kee") < 50 )){
                tell_object(me,"�������״̬̫������ڿ�ʯ��\n");
                return 1;
        }
        
        if(!me->query("occupation") || me->query("occupation") != "��"){
                tell_object(me,"ֻ�п󹤲����ڿ�\n");
                return 1;
        }
                
        if(me->query("combat_exp") < 500000){
                tell_object(me,"�����ѧ���鲻����\n");
                return 1;
        }

        message_vision(HIC"$N�Ӷ����俪ʼ�ڵ�������������\n"NOR,me);
        me->add("sen",-20);
        me->add("kee",-30);
        me->start_busy(6);   
        call_out("wakuang",5,me);
        me->stop_busy();
        return 1;
}

int wakuang(object me)
{
        object ob;

        if (random(10)<7){
                message_vision(CYN"һ���ھ�֮��$NʲôҲû�ڵ���\n"NOR,me);
                return 1;
        }
        else if ((int)me->query("work/wakuang") > 30000 ){
                message_vision(HIR"$N�������ڿ�����������ȥ����һ������ҳ�һ��ÿ�ʯ��\n"NOR,me); 
                me->add("work/wakuang",1);
                ob=new(kuang6[random(7)]);
                ob->move(me);
                ob->set_temp("wakuang/owned",7);
                destruct(this_object());
                return 1;
        }
        else if ((int)me->query("work/wakuang") > 25000 ){
                message_vision(HIY"$N�������ڿ�����������ȥ����һ������ҳ�һ��ÿ�ʯ��\n"NOR,me); 
                me->add("work/wakuang",1);
                ob=new(kuang5[random(6)]);
                ob->move(me);
                ob->set_temp("wakuang/owned",6);
                destruct(this_object());
                return 1;
        }
        else if ((int)me->query("work/wakuang") > 20000 ){
                message_vision(HIY"$N�������ڿ�����������ȥ����һ������ҳ�һ��ÿ�ʯ��\n"NOR,me); 
                me->add("work/wakuang",1);
                ob=new(kuang4[random(5)]);
                ob->move(me);
                ob->set_temp("wakuang/owned",5);
                destruct(this_object());
                return 1;
        }       
        else if ((int)me->query("work/wakuang") > 15000 ){
                message_vision(HIY"$N�ڿ����з�����ȥ���ҳ�һ��ÿ�ʯ��\n"NOR,me); 
                me->add("work/wakuang",1);
                ob=new(kuang3[random(4)]);
                ob->move(me);
                ob->set_temp("wakuang/owned",4);
                destruct(this_object());
                return 1;
        }
        else if ((int)me->query("work/wakuang") > 10000 ){
                message_vision(HIY"$N�ڿ�����������ȥ���þò��ҳ�һ���ʯ��\n"NOR,me); 
                me->add("work/wakuang",1);
                ob=new(kuang2[random(3)]);
                ob->move(me);
                ob->set_temp("wakuang/owned",3);
                destruct(this_object());
                return 1;
        }
        else if ((int)me->query("work/wakuang") > 5000 ){
                message_vision(HIY"$N�ڿ�����������ȥ���ò������ҳ�һ���ʯ��\n"NOR,me); 
                me->add("work/wakuang",1);
                ob=new(kuang1[random(2)]);
                ob->move(me);
                ob->set_temp("wakuang/owned",2);
                destruct(this_object());
                return 1;
        }
        else{ 
                message_vision(HIG"$N���˰��죬���ڷ�������һ��ʯͷ�ǿ�ʯ��\n"NOR,me); 
                me->add("work/wakuang",1);
                ob = new( __DIR__ "obj/tong-kuang");
                ob->move(me);
                ob->set_temp("wakuang/owned",1);
                destruct(this_object());
        }
        return 1;
}
