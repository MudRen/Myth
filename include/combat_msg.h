// combat_msg.h

#ifndef __COMBAT_MSG_H__
#define __COMBAT_MSG_H__

string *guard_msg = ({
        append_color(CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR, CYN),
        append_color(CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR, CYN),
        append_color(CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR, CYN),
        append_color(CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR, CYN),
        append_color(CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR, CYN),
});

string *catch_hunt_msg = ({
        append_color(HIW "$N��$n������������ۺ죬���̴���������\n" NOR, HIW),
        append_color(HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR, HIW),
        append_color(HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR, HIW),
        append_color(HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR, HIW),
        append_color(HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR, HIW),
        append_color(HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR, HIW),
        append_color(HIW "$N�ȵ�����$n�����У���\n" NOR, HIW) });

string *winner_msg = ({
        append_color(CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR, CYN),
        append_color(CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR, CYN),
        append_color(CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR, CYN),
        append_color(CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR, CYN),
        append_color(CYN "\n$n������˼�����˵�����ⳡ�����������ˣ��»ؿ�����ô��ʰ�㣡\n\n" NOR, CYN),
        append_color(CYN "\n$n���һ�ݣ��޺޵�˵�������ӱ���ʮ�겻��\n\n" NOR, CYN),
        append_color(CYN "\n$n��ɫһ����˵�����������ˣ��͵���������ɣ�\n\n" NOR, CYN),
        append_color(CYN "\n$n������Ц���е������������ã��������ã���һ���������������\n\n" NOR, CYN),
        append_color(CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR, CYN),
        append_color(CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR, CYN),
        append_color(CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR, CYN),
});

string damage_msg(int damage, string type)
{
    string str;

//      return "��� " + damage + " ��" + type + "��\n";

    if (damage == 0) return "���û������κ��˺���\n";

    switch( type )
    {
    case "����":
    case "ץ��":
    case "����":
        if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
        else if( damage < 20 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
        else if( damage < 40 ) return "������͡���һ������һ���˿ڣ�\n";
        else if( damage < 80 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
        else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
        else return "���ֻ����$nһ���Һ���$p��$l������һ������ǵĿ����˿ڣ�\n";
        break;
    case "����":
    case "����":
        if( damage < 10 ) return "���ֻ����$n��Ƥ�����������������Ӷ���ࡣ\n";
        else if( damage < 20 ) return "�����$n$l����һ��ϸ����Ѫ�ۡ�\n";
        else if( damage < 40 ) return "��������͡�һ������һ��Ѫ���ܵ��˿ڣ�\n";
        else if( damage < 80 ) return "���ֻ�����ۡ���һ����$n��$l������Ѫ��Ȫӿ��ʹ��$pҧ���гݣ�\n";
        else if( damage < 160 ) return "������ۡ���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
        else return "���ֻ����$nһ���Һ���$p��$l������һ������ǵĿ����˿ڣ�\n";
        break;
    case "ǹ��":
    case "����":
        if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
        else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
        else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
        else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˲���\n";
        else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
        else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ�\n";
        break;
    case "����":
        if( damage < 10 ) return "���ֻ�������һ������$n��Ƥ��������һ��׺ۡ�\n";
        else if( damage < 20 ) return "�����$p��$l���¼���Ѫ�ۡ�\n";
        else if( damage < 40 ) return "���һ�������У�$n��$l��ʱ���ּ���Ѫ�ף�\n";
        else if( damage < 80 ) return "���һ�������У�$n����Ѫ����ע��\n";
        else if( damage < 120 ) return "������꡹��һ����$n��ʱ��Ѫ�ɽ���\n";
        else if( damage < 160 ) return "�����һ�¡��꡹��һ����$n�����û�����Ѫ��\n";
        else return "������꡹���ص����У�$n������ǧ���׿ף�Ѫ���Ĵ���ɣ�\n";
        break;
    case "����":
    case "ȭ��":
    case "����":
        if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
        else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
        else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
        else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
        else if( damage < 120 ) return "������项��һ����$n����������\n";
        else if( damage < 160 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
        else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
        else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ��\n";
        break;
    case "ײ��":
    case "����":
        if( damage < 10 ) return "���ֻ����������������ڸ�$nɦ��һ������\n";
        else if( damage < 20 ) return "�����$p��$l�ҳ�һ��С������\n";
        else if( damage < 40 ) return "����Ҹ����ţ�$n��$l��ʱ����һ���ϸߣ�\n";
        else if( damage < 80 ) return "����Ҹ����ţ�$n�ƺ�һ����Ȼ���˲�С�Ŀ���\n";
        else if( damage < 120 ) return "������项��һ����$n�۵����������ˣ�\n";
        else if( damage < 160 ) return "�����һ�¡��䡹��һ���ҵ�$n��ð���ǣ���һ��ˤ����\n";
        else if( damage < 240 ) return "������ص����У�$n��ǰһ�ڣ����ۡ���һ���³�һ����Ѫ��\n";
        else return "���ֻ�������䡹��һ�����죬$n���ҵ�Ѫ��ģ�����Ҳ��̶ã�\n";
        break;
    case "����":
    case "����":
        if( damage < 20 ) return "�����$n����һ�����ţ����ڸ�$nɦ��һ������\n";
        else if( damage < 40 ) return "���$n����һ�Σ����˵�С����\n";
        else if( damage < 80 ) return "���$n��Ϣһ�ϣ���Ȼ�е����������\n";
        else if( damage < 120 ) return "���$n����һ���ʹ�����������˲��ᣡ\n";
        else if( damage < 160 ) return "������ˡ���һ��$nֻ������ǰһ�ڣ�˫��������ֹ��\n";
        else return "���ֻ�������ˡ���һ�����죬$n���ۡ���һ���³�һ����Ѫ����������������λ��\n";
        break;
    case "����":
    case "����":
        if( damage < 10 ) return "���ֻ����$n��Ƥ�����������������Ӷ���ࡣ\n";
        else if( damage < 20 ) return "�����$n$l���һ����΢���Ϻۡ�\n";
        else if( damage < 40 ) return "�����ž����һ����$n$l���һ��������Ѫ�ۣ�\n";
        else if( damage < 80 ) return "���ֻ����ž����һ����$n��$l�����Ƥ��������ʹ��$pҧ���гݣ�\n";
        else if( damage < 160 ) return "�����ž����һ�����죡��һ�º�������ֻ���$nƤ��������Ѫ���ɽ���\n";
        else return "���ֻ����$nһ���Һ���$w���صس�����$p��$l��$n��ʱѪ���ɣ�ʮ�����˾�����\n";
        break;
    default:
        if( !type ) type = "�˺�";

        if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
        else if( damage < 20 ) str = "��������΢��";
        else if( damage < 30 ) str = "������һ��";
        else if( damage < 50 ) str = "������һ������";
        else if( damage < 80 ) str = "��������Ϊ���ص�";
        else if( damage < 120 ) str = "�������൱���ص�";
        else if( damage < 170 ) str = "������ʮ�����ص�";
        else if( damage < 230 ) str = "�����ɼ������ص�";
        else str =  "�����ɷǳ����µ�����";
        return str + type + "��\n";
    }
}
string eff_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
    if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
    if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
    if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
    if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
    if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
    if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧���Ų�����ȥ��" NOR;
    if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
    if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
    if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
    return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
    if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
    if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
    if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
    if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
    if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
    if( ratio > 40 ) return HIR "�ƺ��ǳ�ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
    if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧���Ų�����ȥ��" NOR;
    if( ratio > 20 ) return HIR "�������Ѿ���������,����Ҫ֧�ֲ�ס�ˡ�" NOR;
    if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
    return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

//report_shen messages
string sen_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "������ͷ�����ѣ�һ��Ҳ���Ժ���" NOR;
    if( ratio > 90 ) return HIG "�������Լ����Դ����ƺ��е㲻̫�þ���" NOR;
    if( ratio > 80 ) return HIY "��������Щ�Ժ��ˡ�" NOR;
    if( ratio > 60 ) return HIY "��ȷ�е��Ժ��ˣ�������ó������ϱ���" NOR;
    if( ratio > 40 ) return HIR "���۷�ֱ���ڽ����ѣ����ǿ�ʼ���ҡ�" NOR;
    if( ratio > 20 ) return HIR "���Ժ�����ҡҡ�λΣ��Ѿ��治�������ϱ��ˡ�" NOR;
    if( ratio > 10 ) return RED "�����Ѿ����ڼ��Ȼ�����,��Ҳ֧�ֲ�ס�ˡ�" NOR;
    return RED "�����Ѿ���ȫ��ʧ����ʱ���п��ܱ�����ȥ��" NOR;
}

#endif

