inherit NPC;
#include <ansi.h>
int give_newbie();
int give_family();
int answer_me();

void create()
{
         set_name("СС����", ({"xiao caishen","caishen"}));
   set ("long", @LONG
���������︺�����ҷ���������(gift)��newbie�����������family���ģ�
�����ϴ�����ʦ���ڣ�bonnet������ҸϿ�����Ҫ��ask���ɡ�
LONG);
           set("gender", "����");
        set("title",HIY"��ӭ�����������߿���վ"NOR);
        set("age", 20);
        set("max_kee", 10000);
        set("kee", 10000);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([
            "bonnet"    : "�����С��������ƽ䡱���Ǹ����ã��ҵ���ʦ���ڹ�ʱ�ˣ�����",
            "newbie"    :(:give_newbie:),
            "gift"    :(:give_newbie:),
            "����"    :(:give_newbie:),
            "family"    :(:give_family:),
            "��������"  :(:give_newbie:),
            "��������"  :(:give_family:),
            "name"      :(:answer_me:),
            "��������"  : "����������ס�����ڣ��пտ��Դ�绰��tel��0755-6888808",
            "stey" : "stey���Ǳ�����������ô�������ⶼ��֪����",
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
/*
           if (who->query("combat_exp") < 100 ){
                command("addoil "+who->query("id") );
                command("say ����������Ҫ���г��ģ�Ҫ��������û��ɱ�ֹ���ѧ,�����������ң���");
                return 1;
         }
*/

         if (this_player()->query("lll/gai") == "got" ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
         
        who->add("combat_exp",180000);
        who->add("daoxing",180000);
        who->add("force",800);
        who->add("mana",800);
        who->add("maximum_force",1500);
        who->add("max_mana",1000);
        who->add("max_force",1000);
        who->add("maximum_mana",1000);
//        who->add("balance",10000);
        who->add("potential",180000);
        who->set("lucky",1);
        who->set("lll/gai","got");
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
        ��ĵ���������һ�ٰ�ʮ��!\n
        ���Ǳ��������180000��\n
        ��������1500��������1000�㷨������������Enableû�г���������ֵ������²��ô�����˼\n");
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
                command("say ����������Ҫ���г��ģ��㿴����������ѧ5000,�����������ң���");
                return 1;
         }
        if (this_player()->query("lll/skills") == "got" ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        if (who->query("combat_exp") > 600000 ) {
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

who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("spells",50);
who->set_skill("literate",50);
who->set_skill("parry",50);
who->set_skill("liangyi-sword",50);
who->set_skill("stick",50);
who->set_skill("dao",50);
who->set_skill("puti-zhi",50);
who->set_skill("qianjun-bang",50);
who->set_skill("wuxiangforce",50);
who->set_skill("unarmed",50);
who->set_skill("jindouyun",50);
who->set_skill("sword",50);
break;
                case "��ԯ��Ĺ":
who->set_skill("force",50);
who->set_skill("jiuyin-force",50);
who->set_skill("sword",50);
who->set_skill("qinghu-jian",50);
who->set_skill("blade",50);
who->set_skill("zizhi-blade",50);
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("whip",50);
who->set_skill("jiuyin-zhua",50);
who->set_skill("youming-spells",50);
who->set_skill("unarmed",50);
who->set_skill("spells",50);
who->set_skill("kongming-steps",50);
break;
                case "��ѩɽ":

who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("force",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("ningxie-force",50);
who->set_skill("dengxian-dafa",50);
who->set_skill("throwing",50);
who->set_skill("unarmed",50);
who->set_skill("xiaoyaoyou",50);
who->set_skill("blade",50);
who->set_skill("bingpo-blade",50);
who->set_skill("cuixin-zhang",50);
who->set_skill("sword",50);
who->set_skill("bainiao-jian",50);
break;
                case "�¹�":     
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("blade",50);
who->set_skill("xuanhu-blade",50);
who->set_skill("baihua-zhang",50);
who->set_skill("literate",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("sword",50);
who->set_skill("snowsword",50);
who->set_skill("moonshentong",50);
who->set_skill("moondance",50);
who->set_skill("moonforce",50);
who->set_skill("whip",50);         
who->set_skill("jueqingbian",50);  
break;                             
               case "����ɽ":      
               case "��һ��":      
               case "������":
               case "��ħ��":
               case "��ʬ��":
               case "�׵���":
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("sword",50);
who->set_skill("huxiaojian",50);
who->set_skill("unarmed",50);
who->set_skill("huxiaoquan",50);
who->set_skill("liushenjue",50);
who->set_skill("stick",50);
who->set_skill("tianyaofa",50);
who->set_skill("literate",50);
who->set_skill("force",50);
who->set_skill("huntianforce",50);
who->set_skill("spells",50);
who->set_skill("tianmogong",50);
who->set_skill("blade",50);
who->set_skill("zileidao",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("parry",50);
break;
                case "��������":  
who->set_skill("unarmed",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("seashentong",50);
who->set_skill("dragonfight",50);
who->set_skill("dragonforce",50);
who->set_skill("dragonstep",50);
who->set_skill("hammer",50);
who->set_skill("huntian-hammer",50);
who->set_skill("literate",50);
who->set_skill("fork",50);
who->set_skill("fengbo-cha",50);
break;
                case "�Ϻ�����ɽ":  
who->set_skill("force",50);
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("spells",50);
who->set_skill("staff",50);
who->set_skill("jienan-zhi",50);
who->set_skill("lotusforce",50);
who->set_skill("lotusmove",50);
who->set_skill("lunhui-zhang",50);
who->set_skill("buddhism",50);
who->set_skill("literate",50);
break;
                case "��˿��":  
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("force",50);
who->set_skill("jiuyin-xinjing",50);
who->set_skill("lanhua-shou",50);
who->set_skill("pansi-dafa",50);
who->set_skill("qingxia-jian",50);
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("qin",50);
who->set_skill("sword",50);
who->set_skill("chixin-jian",50);
who->set_skill("whip",50);
who->set_skill("yinsuo-jinling",50);
who->set_skill("yueying-wubu",50);
break;
                case "�ݿ�ɽ�޵׶�": 
who->set_skill("force",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("blade",50);
who->set_skill("kugu-blade",50);
who->set_skill("yaofa",50);
who->set_skill("literate",50);
who->set_skill("yinfeng-zhua",50);
who->set_skill("sword",50);
who->set_skill("qixiu-jian",50);
who->set_skill("huntian-qigong",50);
who->set_skill("lingfu-steps",50);
who->set_skill("sword",50);
break;
                case "��ׯ��":  
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("spells",50);
who->set_skill("force",50);
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("taiyi",50);
who->set_skill("zhenyuan-force",50);
who->set_skill("xiaofeng-sword",50);
who->set_skill("baguazhen",50);
who->set_skill("hammer",50);
who->set_skill("fumo-zhang",50);
who->set_skill("staff",50);
who->set_skill("wuxing-quan",50);
who->set_skill("blade",50);
who->set_skill("yange-blade",50);
who->set_skill("sanqing-jian",50);
break;
                case "���޵ظ�":  
who->set_skill("unarmed",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("literate",50);
who->set_skill("ghost-steps",50);
who->set_skill("gouhunshu",50);
who->set_skill("tonsillit",50);
who->set_skill("whip",50);
who->set_skill("hellfire-whip",50);
who->set_skill("sword",50);
who->set_skill("jinghun-zhang",50);
who->set_skill("zhuihun-sword",50);
who->set_skill("stick",50);
who->set_skill("kusang-bang",50);
break;
                case "���ƶ�": 
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("literate",50);
who->set_skill("spells",50);
who->set_skill("unarmed",50);
who->set_skill("dali-bang",50);
who->set_skill("fork",50);
who->set_skill("huomoforce",50);
who->set_skill("moshenbu",50);
who->set_skill("moyun-shou",50);
who->set_skill("pingtian-dafa",50);
who->set_skill("yueya-chan",50);
who->set_skill("fork",50);
who->set_skill("huoyun-qiang",50);
who->set_skill("spear",50);
break;
                case "��ɽ����": 
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("force",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("unarmed",50);
who->set_skill("hunyuan-zhang",50);
who->set_skill("whip",50);
who->set_skill("sevensteps",50);
who->set_skill("taoism",50);
who->set_skill("yujianshu",50);
who->set_skill("zixia-shengong",50);
break;
                case "������": 
who->set_skill("literate",50);
who->set_skill("baguazhou",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("unarmed",50);
who->set_skill("archery",50);
who->set_skill("bawang-qiang",50);
who->set_skill("changquan",50);
who->set_skill("lengquan-force",50);
who->set_skill("mace",50);
who->set_skill("spear",50);
who->set_skill("wusi-mace",50);
who->set_skill("xuanyuan-archery",50);
who->set_skill("yanxing-steps",50);
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

void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}

void greeting(object who) {
//382  if( who->query("combat_exp") < 600000) {
// Changed by mudring@sjsh
//384      if (!userp(who)) return ;
if( !who || environment(who) != environment() ) return;
if( who->query("combat_exp") < 600000) {
        tell_object(who,"СС�������ĸ����㣺��������Ҫ����Ŷ(ask)(l xiao caishen)��\n");
        tell_object(who,"СС�������ĸ����㣺��������Ҫ��������Ŷ(ask caishen about family)��\n");
         }
}

