//modified by sgzl for dntg/donghai quest
#include <skill.h>
#include <ansi.h>

int goto_home(); 

inherit NPC;
inherit F_MASTER;

string expell_me(object me);

void create()
{
        set_name(HIC"����"NOR, ({"long fei", "long","fei","longfei","tianshen"}));

        set("long","������ˮ����Ļ���,ӵ�к�ǿ���ˮ������\n");
       set("gender", "����");
       set("age",100);
       set("title", HIC"���ˮ��"NOR);
       set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 5000000);
       set("daoxing", 5000000);
       set("rank_info/respect", "ˮ��");
       set("per", 20);
       set("str", 30);
       set("max_kee", 6000);
       set("max_gin", 400);
       set("max_sen", 6000);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 120);
       set("max_mana", 800);
       set("mana", 1600);
       set("mana_factor", 40);

       set_skill("huntian-hammer", 350);
        set_skill("hammer", 350);
        set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("fork", 350);
       set_skill("spells", 350);
        set_skill("seashentong", 350);
        set_skill("dragonfight", 350);
        set_skill("dragonforce", 350);
        set_skill("fengbo-cha", 350);
        set_skill("dragonstep", 350);
        map_skill("hammer", "huntian-hammer");
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "unarmed", "sheshen" :),
                }) );

        create_family("��������", 1, "ˮ��");
        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
set("inquiry", ([ 
"����": (:goto_home:), 
])); 
        setup();

        carry_object("/d/9ct/zb/pifeng")->wear();
        carry_object("/d/9ct/zb/fork")->wield();
}
void init()
{
        ::init();
        add_action("do_learn", "xuexi");
}


void destroy(object ob)
{
        destruct(ob);
        return;
}

void unsetlearn(object ob)
{
        if (find_player(ob->query("id"))) {
                ob->set_temp("temp/learn", 0);
                ob->save();
                }
}

string *reject_msg = ({
"˵������̫�����ˣ�����ô�ҵ���\n",
        "�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

int do_learn(string arg)
{
        string skill, teacher, master;
        object me= this_player(), ob;
        int master_skill, my_skill, sen_cost;

        if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
                return notify_fail("ָ���ʽ��xuexi <����> from <ĳ��>\n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");

        if( !living(ob) )
                return notify_fail("�ţ���������Ȱ�" + ob->name() + "Ū����˵��\n");

     if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        if (skill != "unarmed" || !me->query_temp("temp/learn") ) 
                return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

        notify_fail(ob->name() + "��Ը���������ܡ�\n");
        if( ob->prevent_learn(me, skill) )
                return 0;

        my_skill = me->query_skill(skill, 1);
        if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

        notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        sen_cost = 250 / (int)me->query_int();

        if( !my_skill ) {
                sen_cost *= 2;
                me->set_skill(skill,0);
        }

        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
        printf("����%s���йء?s������ʡ�\n", ob->name(),
                to_chinese(skill));

        if( ob->query("env/no_teach") )
                return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

        tell_object(ob, sprintf("%s�������йء?s������⡣\n",
                me->name(), to_chinese(skill)));

        if( (int)ob->query("sen") > sen_cost/5 + 1 ) {
                if( userp(ob) ) ob->receive_damage("sen", sen_cost/5 + 1);
        } else {
                write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲô��\n");
                tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
                return 1;
        }
                

        if( (int)me->query("sen") > sen_cost ) {
                if( (string)SKILL_D(skill)->type()=="martial"
&&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        printf("Ҳ���ǵ��в��������%sĻش������޷���ᡣ\n", ob->name() );
                } else {
                        printf("������%s�ָ�����ƺ���Щ�ĵá�\n", ob->name());
                        me->add("learned_points", 1);
                        me->improve_skill(skill, random(me->query_int()));
                }
        } else {
                sen_cost = me->query("sen");
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
        }

        me->receive_damage("sen", sen_cost );

        return 1;
}

void attempt_apprentice(object ob)
{       
        if( (int)ob->query_skill("dragonforce",1) < 50
        || (int)ob->query_skill("seashentong", 1) < 50) {
        command("say " + RANK_D->query_respect(ob) +
                "������ȥ�����ѻ������������������ɡ�\n");
        return;
        }       
        command("smile");
        command("say �ѵ�" + RANK_D->query_respect(ob) +
                "�д���־�������պ���Ŭ����Ϊ�Ҷ����������⡣\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
                   ob->set("title", HIB"��������С����"NOR);
}


int goto_home() 
{
object me=this_player(); 
if(me->query("family/family_name")!="��������")
{ message_vision("$N���Ǳ������ˡ�\n", me); 
 return 1;
}
else {
me->move("/d/9ct/qy/liangong.c");  }
return 1;
}
