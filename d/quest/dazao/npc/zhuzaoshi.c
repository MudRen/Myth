//Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit NPC;
string ask_money();
string ask_imbue();

void create()
{
        set_name("��������ʦ", ({ "bingqi zhuzaoshi", "zhuzaoshi" }));
        set("nickname", HIY"�ɶ��칤"NOR);
        set("gender", "����");
        set("long", "��������ʦ�ļ��ո߳�����˵���������������������ɽ����͡�Īа������������ʦ�ĺ��ˣ�
������������������¼�(name)��\n\n");
        set("age", 41);
        set("attitude", "heroism");
        set("unique", 1);
        set("combat_exp", 100000);
        set("no_quest", 1);
        set("str", 1000);
        set("int", 1000);
        set("con", 1000);
        set("dex", 1000);
        set("jiali", 200);
        set("max_kee", 900000);
        set("max_sen", 900000);
        set("max_mana", 900000);
        set("max_force", 900000);
        set("inquiry", ([  
                "dazao": (: ask_imbue() :),
                "money": (: ask_money :),
                "name": "�����ڸ��������Ҵ���(dazao)�������ܴ����õ�����������.....�ٺ١�

Ҫ�� һ�����������(��������)��
����������������ԴﵽĿǰ����������������������������кܶ฽�����ԡ�

���ƣ� ÿ�˾���һ����ʱ���Դ��죬�Ժ�ÿ������������һ�δ�����ᣬ�úð���Ŷ��\n",
        ]) );
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_temp("apply/dodge", 700);
        set_temp("apply/parry", 700);
        set_temp("apply/attack", 700);
        
        setup();
        carry_object("/d/obj/cloth/linen")->wear();     
}

void init()
{
         ::init();
         add_action("do_imbue","dazao");    
         add_action("do_setimbue","setimbue");      
}

string ask_money()
{
         return "�������Ѿ�׬��" + MONEY_D->money_str(this_object()->query("balance")) + "��";
}

string ask_imbue()
{
         object wp, me = this_player();
         mapping im;
         int i = me->query("get_imbue_weapon");
         
         if( !me->query("occupation") || me->query("occupation") != "����")
                 return "ֻ���������ܴ��������\n";
                
         if( me->query("combat_exp") < 1000000 )
                 return "����Ŀǰ��ˮƽ���ҿ����ò���ʲô�������ģ����Ժ������ɡ�\n";
                
         if ( me->query_temp("dazao_ask/name")|| me->query_temp("dazao_ask/id") ) 
                 return "��������ȥ�Ҵ�����������ԭ���𣿱�ĥ���ˡ�\n";
        
         if( i && i > time() )
                 return "��û������أ����ٵȵȰɣ�\n";
         if( i && i <= time() ){
                 me->delete("get_imbue_weapon");
                 if( !mapp(im = me->query("imbue_weapon")) )
                         return USER_WEAPOND->ask_imbue();
                 me->delete("imbue_weapon");
                 wp = USER_WEAPOND->make_weapon(me, im["type"], im["i"] , im["mar"]);  
                 if( wp )        
                         wp->move(me);
                 else return "�������ɳ�����֪ͨ kuku! \n";
                 
                 me->add("user_weapon_imbued", 1);
                me->add("work/makeweapon",1);
                message("channel:rumor",HIM"��"+HIW"�������"+HIM"��"+me->name()+"����������"+wp->name()+"����������С�\n"NOR,users());
                 message_vision("$N������õ�"+wp->name()+"����$n��\n\n", this_object(), me);
                 write(HIW"��ϸʹ���뿴 uweapon ���\n"NOR);
                 return "��Ū���ˣ�\n";
         }
                 
         return USER_WEAPOND->ask_imbue();
}
// special cmds for Kuku & Koker.
int do_setimbue(string arg)
{
         int i;
        
         // hehe...only 2 of us can do it :-)
         if( geteuid(this_player()) != "kuku" && geteuid(this_player()) != "koker")
                 return 0;
                
         if( !arg )
                 return notify_fail("��ʽ�� setimbue special|super|great|good\n");
        
         if( sscanf(arg, "%d", i)==1 ){
                 USER_WEAPOND->imbue_q(i);
                 return notify_fail("Setimbue -> imbue_sta == "+i+"\n");
         }
        
         if( arg != "special" && arg != "super" && arg != "great" && arg != "good" )
                 return notify_fail("��ʽ�� setimbue special|super|great|good\n");
                 
         USER_WEAPOND->imbue_s(arg);
         return notify_fail("Setimbue -> imbue == "+arg+"\n");
}

int do_imbue(string arg)
{
        object wp, me;
        string type, mar;
        int i,j;
        object *inv; 
        
        if( !living(this_object()) ) return 0;
        
        if( !arg )
                return notify_fail("��ʽ�� dazao <������Ҫ���������>\n");
        
        me = this_player();
        
        if( (int)me->query("get_imbue_weapon") )
                return notify_fail("���ȰѴ��������ȡ����˵��(ask zhuzaoshi about dazao)��\n");
        
        if ( !me->query_temp("dazao_ask/name")||!me->query_temp("dazao_ask/id") ) 
                return notify_fail("�����������ҪЩԭ�ϣ����������(ask zhuzaoshi about dazao)����֪������ҪЩʲô��\n");
                
        if( me->is_fighting() )
                return notify_fail("���������˵�ɡ�\n");
                
        if( me->is_busy() )
                return notify_fail("����æ���ء�\n");
                                
        if( geteuid(me) != "kuku" && geteuid(me) != "koker" && wizardp(me) )
                return notify_fail("��ʦ��ֹ�����������ʹ��clone����õ���Ϸ�����е�������\n");
        
        if( !objectp(wp = present(arg, me)) )
                return notify_fail("������û������������\n");
        
        if( !wp->query("weapon_prop") )
                return notify_fail("����Ŀǰֻ�ܴ���������\n");
        
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("����æ����˵�ɡ�\n");
                
        if( this_object()->is_busy() )
                return notify_fail("����æ���أ��ȵȡ�\n");
                
        if( wp->query("equipped") )
                return notify_fail("Ҫ���죬���ȷ������еı�����\n");
                
        if( wp->query("imbued") )
                return notify_fail("���������Ѿ�������ˡ�\n");
                
        if( !stringp(type = wp->query("skill_type")) )
                return notify_fail("����ֻ�ܴ����ʽ������\n");

        if( !me->query("occupation") || me->query("occupation") != "����")
                return notify_fail("ֻ���������ܴ��������\n");
        
        if( wp->is_corpse() ){ 
                me->start_busy(5);
                message_vision("$N���ŵ����˹�ȥ��\n", this_object());
                this_object()->unconcious();
                return notify_fail("��⣡\n");
        }
        if( me->query("combat_exp") < 1000000 )
                return notify_fail("����Ŀǰ��ˮƽ���ҿ����ò���ʲô�������ģ����Ժ������ɡ�\n");
        
        if( me->query("combat_exp")/2000000 < (int)me->query("user_weapon_imbued") ){
                if( me->query("imbue_reward") )
                        me->delete("imbue_reward");
                else if( !me->query("imbue_paid") )
                        return notify_fail("����Ŀǰ�ľ�����˵��������������Ժ�������ɡ�\n");
        }
        
        if( me->query("imbue_paid") ){
                me->delete("imbue_paid");
                me->add("user_weapon_imbued", -1);
        }
        
        inv = all_inventory(me);                        
        for(j=0; j<sizeof(inv); j++) {
                if (inv[j]->query_temp("dazao_owner")==me->query_temp("dazao_ask/id") ){
                        message_vision("$N����$nһ"+inv[j]->query("unit")+inv[j]->query("name")+"��\n", me,this_object());
                        destruct(inv[j]);
                        me->delete_temp("dazao_ask");

                        switch(type){
                                case "sword": 
                                case "axe":
                                case "blade":
                                case "mace":
                                case "club": 
                                case "dagger":
                                case "fork": 
                                case "hammer": 
                                case "hook":
                                case "spear": 
                                case "staff": 
                                case "stick":
                                case "whip": break;
                                default:
                                        return notify_fail("���ﲻ�ܴ�������������\n");
                        }
        
                        if( wp->id("xiao") ) type = "xiao";     
                        message_vision("$N�ó�"+wp->name()+"��Ҫ$n��æ���졣\n\n",me,  this_object());
                        this_object()->start_busy(2);    
                        me->start_busy(2);
                        mar = wp->query("material");
                        mar = stringp(mar)?mar:"steel"; 
                        destruct(wp);                    
                        if( me->query("combat_exp") > 15000000 && random(me->query("kar")) > 33  
                        && !random(me->query("per")) && !random(me->query("cps")) && me->query("work/makeweapon")>100 )
                                i = 4;          
                        else if( me->query("combat_exp") > 8000000 
                        && random(me->query("kar")) > 26 && random(20) > 15 && me->query("work/makeweapon")>50 )
                                i = 3;
                        else if(  me->query("combat_exp") > 4000000
                        && random(me->query("kar")) > 17 && random(15) > 11 && me->query("work/makeweapon")>20 )
                                i = 2;
                        else if(  random(me->query("kar")) > 12 )
                                i = 1;
                        else i = 0;
        
                        me->set("imbue_weapon/type", type);
                        me->set("imbue_weapon/mar", mar);
                        me->set("imbue_weapon/i", i);
         
                        if( !wizardp(me) ){
                                me->set("get_imbue_weapon", time() + 7200);
                                message_vision("$N���ͷ������һ��ʱ������ȡ�ɡ�\n\n", this_object());
                        }
                        else {
                                message_vision("$N���ͷ����������ˡ�\n\n", this_object());
                                me->set("get_imbue_weapon", 10000);
                        }
                        return 1;
                }
                else{
                        command("say ������û�д��������ԭ�ϡ�\n");
                        return 1;
                }
        }
        return 1;
}
