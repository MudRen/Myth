// liwu.c

inherit NPC;
#include <ansi.h>

#include "2002.h"
int give_newbie();
int give_family();
int give_bag();
int give_book();
int answer_me();
int give_saozhou ();
void create()
{
    set_name("СС����", ({"xiao caishen","caishen"}));
    set ("long", @LONG
���������︺���������ָ���ģ���ҿ�������Ҫ(saozhou)
���򹤣���ʼ�Լ�������������(ask caishen about ɨ���)
LONG);
    set("gender", "����");
    set("title",HIY"��ӭ�����������߿���վ"NOR);
    set("age", 20);
    set("max_kee", 10000);
    set("kee", 10000);
    set("per", 40);
    set("attitude", "peaceful");
    set("inquiry", ([ //
        "bonnet"   : "�����С���˿���¡����Ǹ����ã��ҵ���ʦ���ڹ�ʱ�ˣ�����",
        "��������" : "����������ס�����ڣ��пտ��Դ�绰��tel��0755-6888808",
        "stey"     : "stey���Ǳ�����������ô�������ⶼ��֪����",
       "newbie"    :(:give_newbie:),
         "gift"    :(:give_newbie:),
         "����"    :(:give_newbie:),
       "family"    :(:give_family:),
       "��������"  :(:give_newbie:),
       "��������"  :(:give_family:),
        "�ٱ���"   : (: give_bag :),
        "ħ����"   : (: give_book :),
        "name"     : (: answer_me :),
        "ɨ���"   : (: give_saozhou :),
    ]));

    setup();
    carry_object("/d/lingtai/obj/faguan")->wear();
}

int answer_me()
{
    command("say С���ұ��㣡�ٺ� ��\n");
    return 1;
}


int give_newbie()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") > 410000 ){
                command("hammer "+who->query("id") );
                command("say �㶼��ô�����˻�����ôһ��С����ô��");
                return 1;
         }


         if (this_player()->query("lll/gai") == "got" ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }

        who->add("combat_exp",1800000);
        who->add("daoxing",1800000);
        who->add("force",2800);
        who->add("mana",2800);
        who->add("maximum_force",3000);
        who->add("max_mana",3000);
        who->add("max_force",3000);
        who->add("maximum_mana",3000);

        who->add("potential",8000);
        who->set("lll/gai","got");
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+"
        ��ĵ���������һǧ�˰���!\n
        ���Ǳ��������80000��\n
        ��������3000��������3000�㷨������������Enableû�г���������ֵ������²��ô�����˼\n");
        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ����������");
        return 1;
}
int give_family()
{
        object who=this_player();
        string family;
        family=who->query("family/family_name");
        if (!userp(who))
        {
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }
         if (who->query("combat_exp") < 0 ){
                command("addoil "+who->query("id") );
                command("say ����������Ҫ���г��ģ��㿴����������ѧ15900,�����������ң���");
                return 1;
         }
        if (this_player()->query("lll/skills") == "got" ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        if (who->query("combat_exp") > 70000000 ) {
                        command("hammer "+who->query("id") );
                command("say �㶼��ô�����˻�����ôһ��С����ô��");
                return 1;
         }
        if ( family == 0 )
        {
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ʦ֮ǰ�������\nhelp menpai�����������񻰡��ĸ������ɽ��ܡ�\n");
                return 1;
        }
        switch(family) {
                case "����ɽ���Ƕ�":

                who->set_skill("force",159);
                who->set_skill("dodge",159);
                who->set_skill("spells",159);
                who->set_skill("literate",159);
                who->set_skill("parry",159);
                who->set_skill("liangyi-sword",159);
                who->set_skill("stick",159);
                who->set_skill("dao",159);
                who->set_skill("puti-zhi",159);
                who->set_skill("qianjun-bang",159);
                who->set_skill("wuxiangforce",159);
                who->set_skill("unarmed",159);
                who->set_skill("jindouyun",159);
                who->set_skill("sword",159);
                break;
                                case "��ԯ��Ĺ":
                who->set_skill("force",159);
                who->set_skill("jiuyin-force",159);
                who->set_skill("sword",159);
                who->set_skill("qinghu-jian",159);
                who->set_skill("blade",159);
                who->set_skill("zizhi-blade",159);
                who->set_skill("parry",159);
                who->set_skill("dodge",159);
                who->set_skill("mace",159);
                who->set_skill("jiuyin-zhua",159);
                who->set_skill("youming-spells",159);
                who->set_skill("unarmed",159);
                who->set_skill("spells",159);
                who->set_skill("kongming-steps",159);
                who->set_skill("literate",159);
                break;
                                case "��ѩɽ":

                who->set_skill("literate",159);
                who->set_skill("dodge",159);
                who->set_skill("force",159);
                who->set_skill("spells",159);
                who->set_skill("parry",159);
                who->set_skill("ningxie-force",159);
                who->set_skill("dengxian-dafa",159);
                who->set_skill("throwing",159);
                who->set_skill("unarmed",159);
                who->set_skill("xiaoyaoyou",159);
                who->set_skill("blade",159);
                who->set_skill("bingpo-blade",159);
                who->set_skill("cuixin-zhang",159);
                who->set_skill("sword",159);
                who->set_skill("bainiao-jian",159);
                break;
                                case "�¹�":
                who->set_skill("force",159);
                who->set_skill("dodge",159);
                who->set_skill("unarmed",159);
                who->set_skill("blade",159);
                who->set_skill("xuanhu-blade",159);
                who->set_skill("baihua-zhang",159);
                who->set_skill("literate",159);
                who->set_skill("parry",159);
                who->set_skill("spells",159);
                who->set_skill("sword",159);
                who->set_skill("snowsword",159);
                who->set_skill("moonshentong",159);
                who->set_skill("moondance",159);
                who->set_skill("moonforce",159);
                who->set_skill("whip",159);
                who->set_skill("jueqingbian",159);
                break;
                               case "����ɽ":
                               case "��һ��":
                               case "������":
                               case "��ħ��":
                               case "��ʬ��":
                               case "�׵���":
                who->set_skill("dodge",159);
                who->set_skill("zhaoyangbu",159);
                who->set_skill("sword",159);
                who->set_skill("huxiaojian",159);
                who->set_skill("unarmed",159);
                who->set_skill("huxiaoquan",159);
                who->set_skill("liushenjue",159);
                who->set_skill("stick",159);
                who->set_skill("tianyaofa",159);
                who->set_skill("literate",159);
                who->set_skill("force",159);
                who->set_skill("huntianforce",159);
                who->set_skill("spells",159);
                who->set_skill("tianmogong",159);
                who->set_skill("blade",159);
                who->set_skill("zileidao",159);
                who->set_skill("dodge",159);
                who->set_skill("zhaoyangbu",159);
                who->set_skill("parry",159);
                break;
                                case "��������":
                who->set_skill("unarmed",159);
                who->set_skill("force",159);
                who->set_skill("dodge",159);
                who->set_skill("parry",159);
                who->set_skill("spells",159);
                who->set_skill("seashentong",159);
                who->set_skill("dragonfight",159);
                who->set_skill("dragonforce",159);
                who->set_skill("dragonstep",159);
                who->set_skill("hammer",159);
                who->set_skill("huntian-hammer",159);
                who->set_skill("literate",159);
                who->set_skill("fork",159);
                who->set_skill("fengbo-cha",159);
                break;
                                case "�Ϻ�����ɽ":
                who->set_skill("force",159);
                who->set_skill("parry",159);
                who->set_skill("dodge",159);
                who->set_skill("unarmed",159);
                who->set_skill("spells",159);
                who->s
("staff",159);
                who->set_skill("jienan-zhi",159);
                who->set_skill("lotusforce",159);
                who->set_skill("lotusmove",159);
                who->set_skill("lunhui-zhang",159);
                who->set_skill("buddhism",159);
                who->set_skill("literate",159);
                break;
                                case "��˿��":
                who->set_skill("dodge",159);
                who->set_skill("unarmed",159);
                who->set_skill("parry",159);
                who->set_skill("spells",159);
                who->set_skill("force",159);
                who->set_skill("jiuyin-xinjing",159);
                who->set_skill("lanhua-shou",159);
                who->set_skill("qingxia-jian",159);
                who->set_skill("sword",159);
                who->set_skill("literate",159);
                who->set_skill("qin",159);
                who->set_skill("sword",159);
                who->set_skill("chixin-jian",159);
                who->set_skill("whip",159);
                who->set_skill("yinsuo-jinling",159);
                who->set_skill("yueying-wubu",159);
                break;
                                case "�ݿ�ɽ�޵׶�":
                who->set_skill("force",159);
                who->set_skill("spells",159);
                who->set_skill("parry",159);
                who->set_skill("dodge",159);
                who->set_skill("unarmed",159);
                who->set_skill("blade",159);
                who->set_skill("kugu-blade",159);
                who->set_skill("yaofa",159);
                who->set_skill("literate",159);
                who->set_skill("yinfeng-zhua",159);
                who->set_skill("sword",159);
                who->set_skill("qixiu-jian",159);
                who->set_skill("huntian-qigong",159);
                who->set_skill("lingfu-steps",159);
                who->set_skill("sword",159);
                break;
                                case "��ׯ��":
                who->set_skill("parry",159);
                who->set_skill("dodge",159);
                who->set_skill("unarmed",159);
                who->set_skill("spells",159);
                who->set_skill("force",159);
                who->set_skill("sword",159);
                who->set_skill("literate",159);
                who->set_skill("taiyi",159);
                who->set_skill("zhenyuan-force",159);
                who->set_skill("xiaofeng-sword",159);
                who->set_skill("baguazhen",159);
                who->set_skill("hammer",159);
                who->set_skill("fumo-zhang",159);
                who->set_skill("staff",159);
                who->set_skill("wuxing-quan",159);
                who->set_skill("blade",159);
                who->set_skill("yange-blade",159);
                who->set_skill("sanqing-jian",159);
                break;
                                case "���޵ظ�":
                who->set_skill("unarmed",159);
                who->set_skill("force",159);
                who->set_skill("dodge",159);
                who->set_skill("parry",159);
                who->set_skill("spells",159);
                who->set_skill("literate",159);
                who->set_skill("ghost-steps",159);
                who->set_skill("gouhunshu",159);
                who->set_skill("tonsillit",159);
                who->set_skill("whip",159);
                who->set_skill("hellfire-whip",159);
                who->set_skill("sword",159);
                who->set_skill("jinghun-zhang",159);
                who->set_skill("zhuihun-sword",159);
                who->set_skill("stick",159);
                who->set_skill("kusang-bang",159);
                break;
                                case "���ƶ�":
                who->set_skill("force",159);
                who->set_skill("dodge",159);
                who->set_skill("parry",159);
                who->set_skill("literate",159);
                who->set_skill("spells",159);
                who->set_skill("unarmed",159);
                who->set_skill("dali-bang",159);
                who->set_skill("fork",159);
                who->set_skill("huomoforce",159);
                who->set_skill("moshenbu",159);
                who->set_skill("moyun-shou",159);
                who->set_skill("pingtian-dafa",159);
                who->set_skill("yueya-chan",159);
                who->set_skill("fork",159);
                who->set_skill("huoyun-qiang",159);
                who->set_skill("spear",159);
                break;
                                case "��ɽ����":
                who->set_skill("sword",159);
                who->set_skill("literate",159);
                who->set_skill("dodge",159);
                who->set_skill("force",159);
                who->set_skill("parry",159);
                who->set_skill("spells",159);
                who->set_skill("unarmed",159);
                who->set_skill("hunyuan-zhang",159);
                who->set_skill("whip",159);
                who->set_skill("sevensteps",159);
                who->set_skill("taoism",159);
                who->set_skill("yujianshu",159);
                who->set_skill("zixia-shengong",159);
                break;
                                case "������":
                who->set_skill("literate",159);
                who->set_skill("baguazhou",159);
                who->set_skill("force",159);
                who->set_skill("dodge",159);
                who->set_skill("spells",159);
                who->set_skill("parry",159);
                who->set_skill("unarmed",159);
                who->set_skill("archery",159);
                who->set_skill("bawang-qiang",159);
                who->set_skill("changquan",159);
                who->set_skill("lengquan-force",159);
                who->set_skill("mace",159);
                who->set_skill("spear",159);
                who->set_skill("wusi-mace",159);
                who->set_skill("xuanyuan-archery",159);
                who->set_skill("yanxing-steps",159);
                break;
        default:
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ʦ֮ǰ�������\nhelp menpai�����������񻰡��ĸ������ɽ��ܡ�\n");
                return 1;
}
        who->set("lll/skills","got");
        command("nod "+who->query("id") );
        command("chat "+family+"����"+who->query("name")+"�õ������ɽ�����ϣ���Ժ��Ϊ���������⡣");
        return 1;
}

/*
void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}

void greeting(object who) {

if( !who || environment(who) != environment() ) return;
if( who->query("combat_exp") < 600000) {
        tell_object(who,"СС�������ĸ����㣺��������Ҫ����Ŷ(ask)(l xiao caishen)��\n");
        tell_object(who,"СС�������ĸ����㣺��������Ҫ��������Ŷ(ask caishen about family)��\n");
         }
}
*/
int give_bag()
{
    object bag,who;
    who = this_player();

        if (who->query("daoxing") < 500000 && !metep(who))
    {
        command("addoil "+who->query("id") );
                command("say �ðٱ�����Ҫ��������,�����������ң�");
        return 1;
    }

    if (present("baibao bag",who))
    {
         message_vision("$N����$n����һ����\n",this_object(), who);
         return 1;
    }
    bag =new("/obj/sjsh_bag");
    if (!objectp(bag))
    {
        command("say �ٱ���һʱ���õ����ȵȣ�");
        return 1;
    }

    bag->set("owner_id", who->query("id"));
    who->start_busy(3);

    if (!who->query("sjsh_bag"))
    {
        who->set("sjsh_bag",1);
        bag->save();
        who->save();
    }
    if (bag->restore())
    {
        bag->save();
        bag->move(who);
        message_vision("$N����$n���ص�Ц��Ц��\n$N�ó�һ�������񻰰ٱ�������$n��\n",
                       this_object(), who);
        return 1;
    } else
    {
        command("say �ٱ���һʱ���õ����ȵȣ�");
        destruct(bag);
        return 1;
    }
}

int give_book()
{
    object book, who;
    who = this_player();

    if (present("magic book",who))
    {
        message_vision("$N����$n����һ����\n",this_object(),this_player());
        return 1;
    }

    book =new("/obj/book/magic_book");
    if (!book)
    {
         command("say ħ����һʱ���õ����ȵȣ�");
         return 1;
    }

    book->set("owner_id",who->query("id"));
    who->start_busy(3);

    book->move(who);
    message_vision("$N����$n���ص�Ц��Ц��\n$N�ó�һ��"+book->name()+"����$n��\n",
                   this_object(),who);
    return 1;
}

int give_saozhou ()
{
    object ob;
    object who = this_player();

    if (present("sao zhou", who))
    {
        command_function("hmm");
        tell_object(who, CYN"�㲻�Ǹ��ù����뵹������\n"NOR);
        return 1;
    }
    command_function("nod");
    ob = new("/d/quest/small/saozhou");
    ob->move(who);
    tell_object(who, CYN"СС�����ó�һ�Ѵ�ɨ����㣬ȥɨ��ְɣ�\n"NOR);
    tell_object(who, "�������(look saozhou)����ð�����\n");
    return 1;
}



