// Update by Aeddy@2004-1-6

#include <ansi.h>
#include <login.h>

inherit NPC;

void create()
{
        string *my_name = ({ "���", "���", "��å" });
        string *ob_name = ({ "С�к�", "СŮ��", "������", "С����", "����", 
                             "��ͷ��", "��̫̫" });

        set_name(my_name[ random( sizeof(my_name) ) ], ({ "rascal" }) );
        set("help_ob_name", ob_name[ random( sizeof(ob_name) ) ]);
        set("long", sprintf("����һ��%s�����Ӻ��׺ݡ�\n", name()));

        set("attitude", "heroism");
        set("age", random(20) + 20);
        set("race", "��ħ" );

        set("str", 20 + random(11));            // ����         
        set("cps", 20 + random(11));            // ����
        set("cor", 20 + random(11));            // ����         
        set("per", 20 + random(11));            // ����
        set("int", 20 + random(11));            // ����         
        set("con", 20 + random(11));            // ����
        set("spi", 20 + random(11));            // ����         
        set("kar", 20 + random(11));            // ��Ե

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                sprintf("%s�ȵ������첻�����ѵ�㣬Ҳ��֪�����ӵ�������\n", name()),
                sprintf("%s�ȵ���������£����ò��ͷ��˰ɣ�\n", name()),
                sprintf("%s�ȵ����ޣ���ү����Ҳ�ܣ�ȥ���ɣ�\n", name()),
        }) );
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("force", 3500);
        set("max_force", 3500);          
        set("force_factor", 50);
        set("mana", 3500);      
        set("max_mana", 3500);          
        set("mana_factor", 50);
        set("sen", 5000);
        set("kee", 5000);

        set_skill("force", random(100) + 100 );
        set_skill("spells", random(100) + 100 );
        set_skill("unarmed", random(100) + 100 );
        set_skill("parry", random(100) + 100 );
        set_skill("dodge", random(100) + 100 );
        set("combat_exp", random(400000) + 900000);
        
        setup();

        carry_object("/obj/cloth")->wear();
}

void do_move()
{
        object *ob, me, player;
        int n, i;

        ob = users();
        i = sizeof(ob);
        i--;
        if( i< 0) return;
        me = this_object();
        player = ob[ random(i) ];

        if( wizardp(player) ) return;
        if( !environment(player) || player->is_fighting() 
        || player->query("combat_exp") < 150000 ) {
                me->move(START_ROOM);
                return;
        }

        me->move( environment(player) );
        n = player->query("combat_exp") + random(10000) - 5000;
        if( n <= 0 ) n = random(5000) + 1;
        set("combat_exp", n );

        n = player->query_skill("force", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("force", n );
        n = player->query_skill("unarmed", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("unarmed", n );
        n = player->query_skill("parry", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("parry", n );
        n = player->query_skill("dodge", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("dodge", n );

        message("system",HIW"��"HIR"С����Ϣ"NOR HIW"����˵��"+me->name()+NOR HIW" ����Ϊ���������۸�һλ������"NOR HIW+me->query("help_ob_name")+" \n"NOR,users());    

        tell_object(player, HIR"��ͻȻ����Զ������һ��������������������Ⱦ��Ұ�������\n"NOR);
        tell_object(player, sprintf(WHT"�㼱æ�ܹ�ȥһ����ԭ����һ��%s�����۸�һλ������%s��\n"NOR, 
                me->name(), me->query("help_ob_name")));
        message_vision( sprintf( HIR"$N��%s�ȵ������󵨿�ͽ�����ڹ��컯��֮����ѹ���գ���\n"NOR, me->name() ), player);
        message_vision( sprintf( HIR"%s��$N�ȵ�������Ҫ���ˣ��ҹܴ�ү�����£���\n"NOR, me->name() ), player);

        me->kill_ob( player );
        player->kill_ob( me );
}

void afterdie_func(object killer)
{
        object me;
        int m, n, i;

        me = this_object();
        message("system", HIW"��"HIR"С����Ϣ"NOR HIW"����˵��"+killer->name(1)+"("+killer->query("id")+")�����"+me->name()+"�������˿�����"+me->query("help_ob_name")+" \n" NOR, users() );

        message_vision( sprintf( "$N�����%s�������˿�����%s��\n",me->name(1), me->query("help_ob_name") ), killer);
        message_vision( "����$N��������֣�$N�õ��˽�����\n", killer);

        i = killer->query("daoxing") / 10000;
        if( i > 1000 ) i = 1000;
        m = random(50) + i / 10 + 1;
        n = random(500) + i + 1;
        killer->add("potential", m);
        killer->add("daoxing", n);
        tell_object(killer, sprintf("���Ǳ��������%s�㣡\n", chinese_number(m)));
        tell_object(killer, sprintf("��ĵ���������%s�㣡\n", chinese_number(n)));
}

