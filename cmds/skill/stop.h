/*
        "cor":"��ʶ",
        "cps":"����",
����������Ӧ�����Զ�power��Ӱ��
*/
// ���������߾��������һЩ�鷳.
// �������ݶ��ǲ��Գ�����.
// Reduce the power of the combat_exp
// mudring Nov/22/2002
int valid_power(int combat_exp)
{
    if (combat_exp < 8000000)
        return combat_exp;

    combat_exp -= 8000000;
    if (combat_exp < 4000000)
        return 8000000 + combat_exp / 10;

    combat_exp -= 4000000;
    return 8000000 + (4000000 / 10) + (combat_exp / 20);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int status, level, power;
    mapping dbase;
    mapping temp;
    mapping apply;

    if (!living(ob)) return 0;

    level       = ob->query_skill(skill);
    dbase       = ob->query_entire_dbase();
    temp        = ob->query_entire_temp_dbase();
    if (temp) apply = temp["apply"];

    switch (usage)
    {
    case SKILL_USAGE_ATTACK:
        // what is the following?
        // mudring delete Nov/22/2002
        // level = ob->eff_skill_level(level, SKILL_USAGE_ATTACK);
        if (apply) level += apply["attack"];
        break;
    case SKILL_USAGE_DEFENSE:
        // level = ob->eff_skill_level(level, SKILL_USAGE_DEFENSE);
        if (apply) level += apply["defense"];
        break;
    }

    if (level < 1)
    {
        power = valid_power(dbase["combat_exp"]) / 2;
        // ���ӵ�ʶ(cor)�Ͷ���(cps)�Թ���������Ӱ��
        // mudring Nov/24/2002
        if (usage == SKILL_USAGE_ATTACK)
            power = power / 25 * (dbase["cor"]?dbase["cor"]:25);
        else
            power = power / 25 * (dbase["cps"]?dbase["cps"]:25);

        return  power;
    }

    power = (level * level * level) / 60;
    if ((status = dbase["max_sen"]) > 0)
    {
        if (power > 100000)
            power = power / status * dbase["sen"];
        else
            power = power * dbase["sen"] / status;
    }

    // ���ӵ�ʶ(cor)�Ͷ���(cps)�Թ���������Ӱ��
    // mudring Nov/24/2002
    if (usage == SKILL_USAGE_ATTACK)
        power = (power + valid_power(dbase["combat_exp"])) /
            25 * (dbase["cor"]?dbase["cor"]:25);
    else
        power = (power + valid_power(dbase["combat_exp"])) /
            25 * (dbase["cps"]?dbase["cps"]:25);

//166      power += (valid_power(dbase["combat_exp"]) / 20);

    // �ȼ���power��Ӱ�죬�д�����...
    // ��ý��ȼ���������exp...
    power = power / 20 * ((dbase["level"] > 20)?dbase["level"]:20);

    return power;
}

