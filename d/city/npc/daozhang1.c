#include <ansi.h>

inherit NPC;

string test_player();

mapping *poisons = ({
        ([      "name": "double_ice_poison",
                "base_amount": 100
        ]),
        ([      "name": "ice_poison",
                "base_amount": 50
        ]),
        ([      "name": "jjf_poison",
                "base_amount": 10
        ]),
        ([      "name": "snake_poison",
                "base_amount": 10
        ]),
    ([     "name": "bp_poison",
        "base_amount": 10
    ]),
        ([      "name": "moon_poison",
                "base_amount": 100
        ]),
});
string apply_occupation(object me);
int ask_leave();

void create()
{
        set_name("��Ԩ����", ({"wuyuan daozhang", "wuyuan", "daozhang","taoist"}));
        set("age", 62);
        set("gender", "����");
        set("long",
"����۵����֣��������ɷ���ǣ�\n");
        set("attitude", "peaceful");
        set("class", "taoist");
        set("combat_exp", 180000);
  set("daoxing", 800000);

        set("shen_type", 1);

        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("whip", 90);
        set_skill("force", 90);
        set_skill("spells", 80);
        set_skill("dao", 80);
        map_skill("spells", "dao");
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 10);
        set("mana", 1000);
        set("max_mana", 600);
        set("mana_factor", 30);

        set("max_kee", 800);
        set("max_sen", 700);

        set("eff_dx", 80000);
        set("nkgain", 300);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :)
        }) );

        set("inquiry", ([   
                "name": "ƶ����Ԩ���������־���ƶ����",
                "here": "ƶ����ͨҽ����Ҫ�β�(cure)Ҳ��ƶ���������Կ���",
                "cure": (: test_player :),
                "�β�": (: test_player :),
                "ְҵ" : (: apply_occupation :),
                "leave": (: ask_leave :),
        ]));

        set("chat_chance", 20);
        set("chat_msg", ({
"��Ԩ����̾���������ѣ���������Ī�ѽ������У�\n",
}) );
        setup();
        carry_object("/d/obj/weapon/whip/fuchen")->wield();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

void init()
{
        add_action("do_yes","yes");
        call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        if( !who->query("occupation") ) {
                tell_object(who,"��Ԩ�������ĸ����㣺������ҽʦЭ��(ask daozhang about ְҵ)�ɣ��кܶ�ô�ม�\n");  
        }
}

string apply_occupation(object me)
{
        me=this_player();
        if( me->query("occupation")!= 0 && me->query("occupation") != "ҽʦ"){
                return "�㲻���Ѿ���ְҵ����\n";
        } 
        if( me->is_busy() || me->is_fighting() )
                return "����æ����˵�ɡ�\n";
                
        if( this_object()->is_busy() || this_object()->is_fighting())
                return "����æ���أ��ȵȡ�\n";
                 
        if (me->query("balance") < 1000000)
                return "��Ĵ�������ѡ�\n";
                
        if(me->query("occupation") == "ҽʦ"){
                write("���뻻ְҵ��Ҫ��ְҵ�����뿪(ask daozhang about leave)ҽʦЭ�ᡣ\n");
                return "��˼�����а�����ְҵ����Ҫ�����ܴ���۵�ม�\n";
        }
        me->set_temp("need_zhiye", 1);
        write("������ֻ�����롾ҽʦ�����ְҵ����ȷ��(yes)Ҫ���ְҵ��\n");
        return "��ӭ������ʿ����ҽʦЭ�ᣡ\n";
}

int do_yes()
{
        object me = this_player();
        object ob = this_object();
        
        if (me->query("occupation") != 0)
                return notify_fail("�㲻���Ѿ���ְҵ����\n");
                
        if (me->query("balance") < 1000000){
                command("say ����ְҵ����Ҫ����һ�������Ļ�ѣ���Ŀǰ��û��ô��Ǯ���ɡ�\n");
                return 1;
        }       
        if(me->query_temp("need_zhiye")) {      
                command("say ����ְҵ����Ҫ����һ�������Ļ�ѣ��뿪����Ԥ������˻ء�\n");
                tell_object(me,"��Ĵ��۳�һ�����ƽ�\n"); 
                me->add("balance",-1000000);
                me->set("occupation","ҽʦ");
                tell_object(me,"��ѡ����"+me->query("occupation")+"��Ϊ�������ְҵ��\n");  
                write("�ú÷ܶ��ɣ�����һ��������Ϊ��\n");
                me->delete_temp("need_zhiye");
                me->save();
                return 1;
        }
        return 0;
}

int ask_leave()
{
        object me = this_player();
        object ob = this_object();
        
        if (!me->query("occupation") || me->query("occupation") != "ҽʦ"){
                write("�Ҵ�ط��˰ɣ�\n");
                return 1;
        }
        if ( me->query("occupation") == "ҽʦ" && me->query_skill("medical",1) < 30 ){
                write("������ô��������뿪�����˵�ɣ�\n");
                return 1;
        }
        
        if (me->query("balance") < 1000000){
                write("��Ĵ����������ѡ�\n");
                return 1;
        }
        command("sigh " +me->query("id"));  
        command("say �˸���־����Ȼ��ȥ���Ѿ���Ҳֻ������ȥ�ˡ�\n");  
        command("say �뿪����Ҫ��һ�������������ѣ��뿪��ɡ�\n");
        me->add("balance",-1000000);
        me->delete_skill("medical",1);
        me->delete("occupation");
        return 1;
}

string test_player()
{
        object me=this_player(), npc=this_object();
        mapping poison;
        int i;
        int amount, duration, total;

        total=0;
        message_vision(CYN "$n������֣�����$N�����ϡ�\n"NOR, me, npc);
        message_vision(CYN "����Ƭ�̣�$n����˵����\n" NOR, me, npc);
        for(i=0;i<sizeof(poisons);i++) {
                poison=poisons[i];
                duration=me->query_condition(poison["name"]);
                if(duration>0) {
                        amount=poison["base_amount"]*duration;
                        message_vision(CYN ""+poison["name"]+"��"+chinese_number(amount)+"������,\n" NOR, me, npc);
                        total+=amount;
                }
        }
        if(me->query("eff_kee")<me->query("max_kee")) {
                duration=me->query("max_kee")-me->query("eff_kee");
                amount=duration;
                message_vision(CYN "��Ѫ��"+chinese_number(amount)+"������,\n" NOR, me, npc);
                total+=amount;
        }
        if(me->query("eff_sen")<me->query("max_sen")) {
                duration=me->query("max_sen")-me->query("eff_sen");
                amount=duration;
                message_vision(CYN "����"+chinese_number(amount)+"������,\n" NOR, me, npc);
                total+=amount;
        }
        me->set_temp("cure_payment", total);
        if(total>0) {
                message_vision(CYN "һ����Ҫ"+chinese_number(total)+"��������\n" NOR, me, npc);
                return "��ҽҩ�Ѱɣ�";
        }
        message_vision(CYN ""+RANK_D->query_respect(me)+"��û������ô�Σ�\n" NOR, me, npc);
        return "һ����ȥ��";
}

int accept_object(object who, object ob)
{
        object me = this_object();
        mapping poison;
        int total = who->query_temp("cure_payment");
        int value=ob->value();
        int duration,i;

        if(total==0) {
                command("say "+RANK_D->query_respect(who)+"���Ǹ�ʲô��");
                return 0;
        }
        if(total*100>value) {
                command("say ҽҩ��һ����Ҫ"+chinese_number(total)+"��������");
                return 0;
        }
        message_vision(CYN "$N�ͳ���֧���룬����$n���У�ӡ�ã������͹�����ϥ�������Ѩ����\n" NOR, me, who);
        message_vision(CYN "Ƭ��֮��$N������һһ���£�\n$nֻ����ɤ���۷��̣������³�һ����ʰ�쵵���Ѫ��\n" NOR, me, who);
        command("pat "+who->query("id"));
        command("say ����ˡ�");
        for(i=0;i<sizeof(poisons);i++) {
                poison=poisons[i];
                duration=who->query_condition(poison["name"]);
                if(duration>0) {
                        who->apply_condition(poison["name"], 0);
                }
        }
        who->set("eff_kee", who->query("max_kee"));
        who->set("eff_sen", who->query("max_sen"));
        return 1;
}
